ALL: Factorial Integral Time_Child pstree	
CFLAGS=-std=c11 -w

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o  Factorial Time_Child pstree Integral

Factorial: exercise1.o
	gcc -g exercise1.o -o Factorial

exercise1.o: exercise1.c
	gcc -g -c $(CFLAGS) exercise1.c

Integral: exercise2.o
	gcc -g exercise2.o -o Integral

exercise2.o: exercise2.c
	gcc -g -c $(CFLAGS) exercise2.c

Time_Child: excercise3.o
	gcc -g excercise3.o -o Time_Child

excercise3.o: excercise3.c
	gcc -g -c $(CFLAGS) excercise3.c

pstree: exercise4.o
	gcc -g exercise4.o -o pstree

exercise4.o: exercise4.c
	gcc -g -c $(CFLAGS) exercise4.c

