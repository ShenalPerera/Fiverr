CC = gcc
CFLAGS = -g -Wall -Wextra

all: tcpclient async-tcpserver

tcpclient: tcpclient.c
	$(CC) $(CFLAGS) -o tcpclient tcpclient.c

async-tcpserver: async-tcpserver.c
	$(CC) $(CFLAGS) -o async-tcpserver async-tcpserver.c

clean:
	rm -f tcpclient async-tcpserver