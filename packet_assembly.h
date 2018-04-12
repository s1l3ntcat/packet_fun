/*
###################
#
# Author: silentcat
# Date: 2018-04-10
# Description: Declares functions
# for the assembly of the packet!
#
###################
*/

#include "udp_pkt.h"
#include "ip_pkt.h"

/* Functions */

void *assemble_pkt(UDP *u, IP *i, void *data, u_short_pkt data_len); // Assembles a packet.
int send_packet(struct sockaddr_in *sa, void *pkt, u_short_pkt pkt_len); // Sends a packet.
