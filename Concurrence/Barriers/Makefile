ALL: barrier
CFLAGS=-pthread -w

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o barrier

barrier: ex1.c
	gcc $(CFLAGS) ex1.c -g -o barrier

