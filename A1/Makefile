main:
	gcc -ansi -Wall -c file_size.c
	gcc -ansi -Wall -c read_words.c
	gcc -ansi -Wall -c printWordsAlphabetically.c
	gcc -ansi -Wall -c print_words.c
	gcc -ansi -Wall -c alphabetical_word_count.c
	gcc -ansi -Wall -c print_alphabetical_word_count.c
	gcc -ansi -Wall -c create_alphabetical_array.c
	gcc -ansi -Wall -c free_alphabetical_array.c
	gcc -ansi -Wall main.c free_alphabetical_array.o create_alphabetical_array.o alphabetical_word_count.o print_alphabetical_word_count.o print_words.o printWordsAlphabetically.o read_words.o file_size.o -o main

clean:
	rm main *o
