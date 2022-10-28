> Chollada Sae-lim 64050060
 ## Ans Lab9
> A

```c
exitCriticalSection(1);
```

> B

```c
enterCriticalSection(0);
```

> lab9_q1.mk -> goodCnt
```mk
all: lab9_q1

lab9_q1: lab9_q1.o peterson.o
	gcc -o goodCnt lab9_q1.o peterson.o

lab9_q1.o: lab9_q1.c
	gcc -c lab9_q1.c

clean:
	rm -rf *.o goodCnt
```