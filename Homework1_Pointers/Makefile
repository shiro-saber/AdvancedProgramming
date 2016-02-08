ALL:Ships Hospital Quiz
ALL:$(ALL)
CFLAGS=-std=c99

.PHONY:clean

clean:
	@echo Porque Kenny!
	 \rm -f *.o $(ALL)
	 \rm -f Ships Hospital Quiz

resultado: Ships 
	gcc -g Ships.o -o resultado

Ships.o: Ships.c
	gcc -g -c -w Ships.c

resultado2: Hospital
	gcc -g Hospital.o -o resultado2

Hospital.o: Hospital.c
	gcc -g -c -w Hospital.c

resultado3: Quiz
	gcc -g Quiz.o -o resultado3

Quiz.o: Quiz.c
	gcc -g -c -w Quiz.c
