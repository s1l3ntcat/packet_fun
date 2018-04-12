/*
################
#
# Author: silentcat
# Date: 2018-04-10
# Description: Assembles
# a packet.
#
#################
*/

#include "packet_assembly.h"

void *assemble_pkt(UDP *u, IP *i, void *data, u_short_pkt data_len)
{
	int size = UDP_SIZE + IP_SIZE + data_len; // Compute entire length of packet.
	void *pkt = malloc(size); // Allocate memory to packet.
	if (!pkt) // If the packet wasn't allocated, report errors.
	 {
		perror("malloc");
		return NULL;
	 }

	memset(pkt, 0, size); // Clear the packet's memory.
	memcpy(pkt, i, IP_SIZE); // Copy the IP header.
	memcpy(pkt + IP_SIZE, u, UDP_SIZE); // Copy the UDP header after that.
	if (data) memcpy(pkt + IP_SIZE + UDP_SIZE, data, data_len); // Finally, copy the data.
	return pkt;
}

int send_packet(struct sockaddr_in *sa, void *pkt, u_short_pkt pkt_len)
{
	int s = socket(AF_INET, SOCK_RAW, IPPROTO_RAW); // Creates a raw, UDP socket.
	if (s == -1) // Checks that the socket was created.
	 {
		perror("socket");
		return -1;
	 }

	if (sendto(s, pkt, pkt_len, 0, (struct sockaddr *) sa, sizeof(struct sockaddr)) == -1) // Sends the packet to the destination.
	 {
		perror("sendto"); 
		close(s);
		return -1;
	 }

	close(s); // Closes the socket.
	return 0;
}
