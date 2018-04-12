/*
#################
#
# Author: silentcat
# Date: 2018-04-10
# Description: Declares
# functions for constructing
# UDP packets and for 
# manipulating them.
#
#################
*/


#ifndef PKT_FUN_UDP_PKT
#define PKT_FUN_UDP_PKT

#include "definitions.h"

/* Macros */

#define UDP_SIZE sizeof(UDP)
#define UDP_PROTO 17

/* Structure */

typedef struct udp_pkt
{
	u_short_pkt src; // The source port.
	u_short_pkt dst; // The destination port.
	u_short_pkt len; // The length of the header + data.
	u_short_pkt chksum; // The checksum of the header + data.

} UDP;

/* Functions */

UDP *construct_udp_hdr(u_short_pkt src, u_short_pkt dst, u_short_pkt len); // Constructs a UDP packet.
u_short_pkt calculate_chksum(UDP *u, void *data); // Calculates the checksum given the data.

#endif
