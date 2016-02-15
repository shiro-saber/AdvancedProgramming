ALL: factorial1 sum factorial_pipes fifo_read fifo_write
ALL:$(ALL)
CFLAGS=-std=c99 -w

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o factorial1 sum factorial_pipes fifo_read fifo_write

factorial1: pipe_factorial.c
	gcc $(CFLAGS) pipe_factorial.c -g -o factorial1

sum: pipe_sum.c
	gcc $(CFLAGS) pipe_sum.c -g -o sum

factorial_pipes: factorial_multipipes.c
	gcc $(CFLAGS) factorial_multipipes.c -g -o factorial_pipes

fifo_read: fifo_read.c
	gcc $(CFLAGS) fifo_read.c -g -o fifo_read

fifo_write: fifo_write.c
	gcc $(CFLAGS) fifo_write.c -g -o fifo_write

