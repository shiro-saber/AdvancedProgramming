ALL: ex1 ex2 ex3
CFLAGS=-std=c99 -fopenmp

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o ex1 ex2 ex3

ex1: ex1.c
	gcc $(CFLAGS) ex1.c -g -o ex1

ex2: ex2.c
	gcc $(CFLAGS) ex2.c -g -o ex2

ex3: ex3.c
	gcc $(CFLAGS) ex3.c -g -o ex3
