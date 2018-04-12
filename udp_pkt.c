/*
################
#
# Author: silentcat
# Date: 2018-04-10
# Description: Constructs 
# a UDP packet and calculates
# its checksum.
#
################
*/

#include "udp_pkt.h"

UDP *construct_udp_hdr(u_short_pkt src, u_short_pkt dst, u_short_pkt len)
{
	UDP *udp = malloc(UDP_SIZE); // Allocate the UDP header.
	if (!udp) // Check that the memory was allocated.
	 {
		perror("malloc");
		return NULL;
	 }
	memset(udp, 0, UDP_SIZE); // Clear the memory.
	udp->src = htons(src); // Assign source port.
	udp->dst = htons(dst); // Assign destination port.
	udp->len = htons(UDP_SIZE + len); // Assign the length.
	return udp;
}
