CC=gcc
CFLAGS=-ansi -Wall
C99FLAGS=-std=c99 -Wall

CHAR = Sorted_List_Char.o a4q1a_char.o
INT = Sorted_List_Int.o a4q1a_int.o
A4Q1B = Sorted_List_Int.o a4q1b.o Function_Ptr.o

A4Q2 = Sorted_List_int.o a4q2.o Recursion.o

A4Q3 = Sorted_List_int.o a4q3.o Recursion.o Fractions.o

all: a4q1a_int a4q1a_char a4q1b a4q2 a4q3

a4q1b: $(A4Q1B)
	$(CC) $(CLFAGS) -o a4q1b.out $(A4Q1B)

a4q1b.o: a4q1b.c
	$(CC) $(CFLAGS) -c a4q1b.c -DINT -o a4q1b.o

a4q1a_int: $(INT)
	$(CC) $(CFLAGS) -o a4q1a_int.out $(INT)

a4q1a_int.o: a4q1a_int.c
	$(CC) $(CFLAGS) -c a4q1a_int.c -DINT -o a4q1a_int.o

Function_Ptr.o: Function_Ptr.c
	$(CC) $(CFLAGS) -c Function_Ptr.c -DINT -o Function_Ptr.o

Sorted_List_Int.o: Sorted_List.c
	$(CC) $(CFLAGS) -c Sorted_List.c -DINT -o Sorted_List_Int.o

a4q1a_char: $(CHAR)
	$(CC) $(CFLAGS) -o a4q1a_char.out $(CHAR)

a4q1a_char.o: a4q1a_char.c
	$(CC) $(CFLAGS) -c a4q1a_char.c -DCHAR -o a4q1a_char.o

Sorted_List_Char.o: Sorted_List.c
	$(CC) $(CFLAGS) -c Sorted_List.c -DCHAR -o Sorted_List_Char.o

a4q2: $(A4Q2)
	$(CC) $(CFLAGS) -o a4q2.out $(A4Q2)

a4q2.o: a4q2.c
	$(CC) $(CFLAGS) -c a4q2.c -DINT -o a4q2.o

Recursion.o: Recursion.c
	$(CC) $(CLFLAGS) -c Recursion.c -DINT -o Recursion.o

a4q3: $(A4Q3)
	$(CC) $(C99FLAGS) -o a4q3.out $(A4Q3)

a4q3.o: a4q3.c
	$(CC) $(C99FLAGS) -c a4q3.c -DFRACT -o a4q3.o

Fractions.o: Fractions.c
	$(CC) $(C99FLAGS) -c Fractions.c -DFRACT -o Fractions.o

Sorted_List_Fract.o: Sorted_List.c
	$(CC) $(C99FLAGS) -c Sorted_List.c -DFRACT -o Sorted_List_Fract.o


clean:
	rm *o *out
