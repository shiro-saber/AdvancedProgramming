ALL: client server
ALL:$(ALL)
CFLAGS=-std=c99 -w

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f server client

server: main.c
	gcc $(CFLAGS) main.c -g -o server

client: client.c
	gcc $(CFLAGS) client.c -g -o client
