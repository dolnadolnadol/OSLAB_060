all: lab9_q1

lab9_q1: lab9_q1.o peterson.o
	gcc -o goodCnt lab9_q1.o peterson.o

lab9_q1.o: lab9_q1.c
	gcc -c lab9_q1.c

clean:
	rm -rf *.o goodCnt