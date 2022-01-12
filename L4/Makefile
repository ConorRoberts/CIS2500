CC=gcc
CFLAGS=-ansi -Wall

all: main

main: main.o createList.o rand_double.o printList.o freeList.o sort1.o sort1Print.o sort2.o sort2Print.o
	$(CC) $(CFLAGS) -o main main.o createList.o rand_double.o printList.o freeList.o sort1.o sort1Print.o sort2.o sort2Print.o
	
createList.o: createList.c
	$(CC) $(CFLAGS) -c createList.c

rand_double.o: rand_double.c
	$(CC) $(CFLAGS) -c rand_double.c

printList.o: printList.c
	$(CC) $(CFLAGS) -c printList.c

freeList.o: freeList.c
	$(CC) $(CFLAGS) -c freeList.c

sort1.o: sort1.c
	$(CC) $(CFLAGS) -c sort1.c

sort1Print.o: sort1Print.c
	$(CC) $(CFLAGS) -c sort1Print.c

sort2.o: sort2.c
	$(CC) $(CFLAGS) -c sort2.c

sort2Print.o: sort2Print.c
	$(CC) $(CFLAGS) -c sort2Print.c

clean:
	rm *o main
