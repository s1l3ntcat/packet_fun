/*
###############
#
# Author: silentcat
# Date: 2018-04-10
# Description: Declares functions for
# constructing an IP packet.
#
###############
*/

#ifndef PKT_FUN_IP_PKT
#define PKT_FUN_IP_PKT

#include "definitions.h"

/* Macro */

#define IP_SIZE sizeof(IP)

/* Structure */

typedef struct ip_pkt
{ 
	u_char_pkt begin_fields; // The beginning fields.
	u_char_pkt tos; // The Type of Service.
	u_short_pkt tot_len; // The Total Length (kernel computed).
	u_short_pkt id; // The ID (kernel computed).
	u_short_pkt frag_off; // The fragment off set (and the flags).
	u_char_pkt ttl; // The Time To Live.
	u_char_pkt proto; // The protocol.
	u_short_pkt chksum; // The checksum (kernel computed).
	u_long_pkt src_ip; // The source address (kernel computed).
	u_long_pkt dst_ip; // The destination address.
} IP;

/* Function */

IP *construct_ip_hdr(u_long_pkt dst_ip, u_char_pkt proto); // Constructs an IP header.

#endif
