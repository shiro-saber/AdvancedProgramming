ALL: void_pointer process pipes client server signals signalset bank movies openmp
CFLAGS=-w -pthread -fopenmp

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o signals void_pointer process pipes client server signalset bank movies openmp

void_pointer: pointers.c
	gcc $(CFLAGS) pointers.c -g -o void_pointer

process: process_exam.c
	gcc $(CFLAGS) process_exam.c -g -o process

pipes: pipes_exam.c
	gcc $(CFLAGS) pipes_exam.c -g -o pipes

client: client.c
	gcc $(CFLAGS) client.c -g -o client

server: server.c
	gcc $(CFLAGS) server.c -g -o server

signals: signals.c
	cc $(CFLAGS) signals.c -g -o signals

signalset: signalset.c
	cc $(CFLAGS) signalset.c -g -o signalset

bank: bank.c
	cc $(CFLAGS) bank.c -g -o bank

movies: movies.c
	cc $(CFLAGS) movies.c -g -o movies

openmp: ompExam.c
	gcc $(CFLAGS) ompExam.c -g -o openmp
