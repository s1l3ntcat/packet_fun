/*
###############
#
# Author: silentcat
# Date: 2018-04-10
# Description: Constructs
# an IP packet.
#
##############
*/

#include "ip_pkt.h"

IP *construct_ip_hdr(u_long_pkt dst_ip, u_char_pkt proto)
{
	IP *iphdr = malloc(IP_SIZE); // Allocate memory to IP header.
	if (!iphdr) // Check that memory was allocated.
	 {
		perror("malloc");
		return NULL;
	 }
	memset(iphdr, 0, IP_SIZE); // Clear memory on the IP header.
	iphdr->begin_fields |= 64;
	iphdr->begin_fields |= 5;
	iphdr->ttl = 64; // Set the TTL to 64.
	iphdr->proto = proto; // Set the protocol to the one specified by the user.
	iphdr->dst_ip = dst_ip; // Set the destination IP to the network byte form of itself.
	return iphdr;
}
