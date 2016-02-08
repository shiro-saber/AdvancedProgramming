ALL: void_pointer process
ALL:$(ALL)
CFLAGS=-std=c99 -w

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o $(ALL) void_pointer process

void_pointer: pointers.o
	gcc -g pointers.o -o void_pointer

pointers.o: pointers.c
	gcc -g -c $(CFLAGS) pointers.c

process: process_exam.o
	gcc -g process_exam.o -o process

process_exam.o: process_exam.c
	gcc -g -c $(CFLAGS) process_exam.c
