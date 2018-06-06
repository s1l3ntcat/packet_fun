/*
#############
#
# Author: silentcat
# Date: 2018-06-05
# Description: Functions and definitions related to an IP packet.
#
############
*/

#include "ip.h"

uint16_t calculate_checksum(void *buf)
{
	uint32_t sum = 0;
	uint16_t *sumbuf = (uint16_t *) buf;

	int word_count = HDR_SIZE;
	while (word_count > 0)
	 {
		sum += *sumbuf++;
		if (sum & 0x10000)
			sum = (sum & 0xFFFF) + 1;
		--word_count;
	 }

	return ~sum;
}

IP *construct_ip_hdr(struct sockaddr_in *src, struct sockaddr_in *dst)
{
	/* Set version and IHL (combined in same field). */

	IP *buf = malloc(sizeof(IP));
	if (!buf)
	 {
		perror("malloc");
		return NULL;
	 }

	memset(buf, 0, sizeof(IP));
	buf->version |= 0x4;
	buf->ihl |= 0x2C;
	buf->tos = 0;
	buf->tot_len = ihl * 4;
	
}

void send_pkt(int s, void *pkt, struct sockaddr_in *dst)
{


}
