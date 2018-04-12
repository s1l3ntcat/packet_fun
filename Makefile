

all:
	cc -g -Wall main.c packet_assembly.c udp_pkt.c ip_pkt.c -o main
