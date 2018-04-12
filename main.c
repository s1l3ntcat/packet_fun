/*
##################
#
# Author: silentcat
# Date: 2018-04-10
# Description: The main
# program for sending packets.
#
#################
*/

#include "packet_assembly.h"

int main(int argc, char *argv[])
{

	if (argc != 3)
	 {
		fprintf(stderr, "Usage: ./main [ip] [data]\n");
		return -1;
	 }

	struct sockaddr_in sa;
	int size = strlen(argv[2]);
	char *data = malloc(size + 1);
	if (!data)
	 {
		perror("malloc");
		return -1;
	 }

	memset(data, 0, size + 1); // Clear memory.
	memset(&sa, 0, sizeof(sa)); // Clear memory.
	inet_pton(AF_INET, argv[1], &sa.sin_addr); // Convert string into binary form.
	strncpy(data, argv[2], size);

	UDP *u = construct_udp_hdr(23, 80, size); // Create UDP header.
	IP *i = construct_ip_hdr(sa.sin_addr.s_addr, UDP_PROTO); // Create IP header.
	/* HANDLE ERRORS */
	if (!u)	
	 {
	 	if (i) free(i);
		return -1;
	 }

	if (!i)
	 {
		if (u) free(u);
		return -1;
	 }
	/* HANDLE ERRORS ^ */
	void *pkt = assemble_pkt(u, i, data, size); // Assemble the packet.
	if (!pkt) // Handle errors
	 {
		free(u);
		free(i);
		return -1;
	 }

	sa.sin_family = AF_INET;
	sa.sin_port = UDP_PROTO;
	free(u); // Free UDP header.
	free(i); // Free IP header.
	if (send_packet(&sa, pkt, UDP_SIZE + IP_SIZE + size) == -1) // Send the packet.
	 {
		fprintf(stderr, "Couldn't send packet...\n");
		return -1;
	 }

	printf("Packet sent!\n");
	free(pkt); // Deallocate memory to packet.
	return 0;
}
