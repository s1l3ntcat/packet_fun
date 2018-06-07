/*
#############
#
# Author: silentcat
# Date: 2018-06-06
# Description: Assembles a packet given certain parameters.
#
############
*/

#include "packet_assembly.h"

int get_header_size(int proto)
{
	switch (proto)
	 {
		case IPPROTO_ICMP:
			return sizeof(ICMP);
		default:
			return 0;
	 }
}

void *get_header(int proto, struct args *a)
{
	void *hdr = NULL;
	switch (proto) 
	 {
		case IPPROTO_ICMP:
			hdr = (void *) construct_icmp_hdr();
			if (!hdr)
				return NULL;
			break;
	 }

	return hdr;
}

void *create_pkt(struct sockaddr_in *src, struct sockaddr_in *dst, int proto)
{
	
	int header_size = get_header_size(proto), pkt_size = sizeof(IP) + header_size;
	void *pkt = malloc(pkt_size);
	if (!pkt)
	 {
		perror("malloc");
		return NULL;
	 }

	memset(pkt, 0, pkt_size);
	IP *ip = construct_ip_hdr(src, dst, proto);
	void *hdr = get_header(proto, NULL);
	if (!ip || !hdr)
	 {
		perror("malloc");
		if (ip) free(ip);
		if (hdr) free(hdr);
		free(pkt);
		return NULL;
	 }

	memcpy(pkt, ip, sizeof(IP));
	memcpy(pkt + sizeof(IP), hdr, header_size);
	free(ip);
	free(hdr);
	return pkt;
}
