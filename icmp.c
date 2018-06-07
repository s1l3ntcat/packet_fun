/*
#############
#
# Author: silentcat
# Date: 2018-06-06
# Description: Creates an ICMP packet.
#
############
*/

#include "icmp.h"

ICMP *construct_icmp_hdr()
{
	ICMP *ic = malloc(sizeof(ICMP));
	if (!ic)
	 {
		perror("malloc");
		return NULL;
	 }

	memset(ic, 0, sizeof(ICMP));
	ic->type = ECHO_REQUEST;
	ic->chksum = ~(ic->type + ic->code);
	return ic;
}
