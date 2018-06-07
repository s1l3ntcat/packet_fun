/*
#############
#
# Author: silentcat
# Date: 2018-06-06
# Description: Assembles a packet given certain parameters.
#
############
*/

#ifndef PACKET_ASSEMBLY
#define PACKET_ASSEMBLY

#include "ip.h"
#include "icmp.h"

/* Functions */

int get_header_size(int proto);
void *create_pkt(struct sockaddr_in *src, struct sockaddr_in *dst, int proto);

#endif
