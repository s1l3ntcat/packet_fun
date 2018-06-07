
all:
	cc -g -Wall main.c ip.c icmp.c packet_assembly.c -o main


clean:
	rm -r *.dSYM
	rm make
	rm test.pcap
