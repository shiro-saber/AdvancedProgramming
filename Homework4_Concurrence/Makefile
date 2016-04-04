ALL: dwarfs bathroom dron system
CFLAGS=-pthread -w

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o dwarfs bathroom dron system data

dwarfs: dwarfs.c
	gcc $(CFLAGS) dwarfs.c -g -o dwarfs

bathroom: bathroom.c
	gcc $(CFLAGS) bathroom.c -g -o bathroom

dron: dron.c
	gcc $(CFLAGS) dron.c -g -o dron

system: system.c
	gcc $(CFLAGS) system.c -g -o system

