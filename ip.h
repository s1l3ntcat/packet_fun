/*
#############
#
# Author: silentcat
# Date: 2018-06-05
# Description: Functions and definitions related to an IP packet.
#
############
*/


#ifndef IP_H
#define IP_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/* Macros */

#define HDR_SIZE 20
#define DEFAULT_ID 1234
#define DEFAULT_TTL 123

/* Structures */

typedef struct ip
{
	uint8_t version;
	uint8_t tos;
	uint16_t tot_len;
	uint16_t id;
	uint16_t frag;
	uint8_t ttl;
	uint8_t proto;
	uint16_t chksum;
	uint32_t src;
	uint32_t dst;
} IP;

/* Functions */

uint16_t calculate_checksum(void *buf);
IP *construct_ip_hdr(struct sockaddr_in *src, struct sockaddr_in *dst, int proto);
void send_pkt(int s, void *pkt, int size, struct sockaddr_in *dst);

#endif
