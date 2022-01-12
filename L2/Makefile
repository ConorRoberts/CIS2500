main:
	gcc -ansi -Wall -c rand_foobarbaz.c
	gcc -ansi -Wall -c rand_double.c
	gcc -ansi -Wall -c many_foobarbaz.c
	gcc -ansi -Wall -c print_foobarbaz.c
	gcc -ansi -Wall -c swap_foobarbaz.c
	gcc -ansi -Wall main.c rand_foobarbaz.o swap_foobarbaz.o rand_double.o print_foobarbaz.o many_foobarbaz.o -o main

clean:
	rm main *o
