ALL: ex1 smokers
CFLAGS=-std=c99 -w -pthread

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f ex1 smokers

ex1: ex1.c
	gcc $(CFLAGS) ex1.c -g -o ex1

smokers: smoking.c
	gcc $(CFLAGS) smoking.c -g -o smokers
