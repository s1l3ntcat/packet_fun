/*
#############
#
# Author: silentcat
# Date: 2018-06-06
# Description: Creates an ICMP packet.
#
############
*/

#ifndef ICMP_H
#define ICMP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

/* Macros */

#define ECHO_REPLY 0
#define ECHO_REQUEST 8

/* Structures */

typedef struct icmp_req
{
	uint8_t type;
	uint8_t code;
	uint16_t chksum;
	uint32_t data;

} ICMP;

/* Functions */

ICMP *construct_icmp_hdr(void);

#endif
