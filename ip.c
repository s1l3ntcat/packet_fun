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
		sum += ntohs(*sumbuf++);
		if (sum & 0x10000)
			sum = (sum & 0xFFFF) + 1;
		word_count -= 2;
	 }

	return ~sum;
}

IP *construct_ip_hdr(struct sockaddr_in *src, struct sockaddr_in *dst, int proto)
{

	IP *buf = malloc(sizeof(IP));
	if (!buf)
	 {
		perror("malloc");
		return NULL;
	 }

	memset(buf, 0, sizeof(IP));
	buf->version |= 0x5;
	buf->version |= (0x4 << 4);
	buf->tos = 0;
	buf->tot_len = htons(sizeof(IP) + 8);
	buf->id = htons(DEFAULT_ID);
	buf->frag = 0;
	buf->ttl = DEFAULT_TTL;
	buf->proto = proto;
	buf->src = src->sin_addr.s_addr;
	buf->dst = dst->sin_addr.s_addr;

	buf->chksum = htons(calculate_checksum(buf));

	return buf;
	
}

void send_pkt(int s, void *pkt, 
	int size, struct sockaddr_in *dst)
{
	if (sendto(s, pkt, size, 0, 
		(struct sockaddr *) dst, sizeof(struct sockaddr)) == -1)
	 {
		perror("sendto");
		return;
	 }
}


