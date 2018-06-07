/*
#############
#
# Author: silentcat
# Date: 2018-06-06
# Description: Main program for sending an ICMP packet.
#
############
*/

#include "packet_assembly.h"


int main(int argc, char *argv[])
{
	if (argc != 3)
	 {
		fprintf(stderr, "Usage: ./main [src] [dst]\n");
		return -1;
	 }

	struct sockaddr_in src, dst;
	memset(&src, 0, sizeof(struct sockaddr_in));
	memset(&dst, 0, sizeof(struct sockaddr_in));

	inet_pton(AF_INET, argv[1], &src.sin_addr);
	inet_pton(AF_INET, argv[2], &dst.sin_addr);

	int s = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if (s == -1)
	 {
		perror("socket");
		return -1;
	 }

	void *pkt = create_pkt(&src, &dst, IPPROTO_ICMP);
	if (!pkt)
	 {
		close(s);
		return -1;
	 }

	send_pkt(s, pkt, sizeof(ICMP) + sizeof(IP), &dst);
	return 0;
}
