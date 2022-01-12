CC=gcc
CFLAGS=-ansi -Wall

all: frequency_table decode copyrecords

copyrecords: copyrecords.o decode.o chi_sq.o to_decode.o encode.o encode_shift.o letter_count.o add_letters.o create_freq_table.o file_size.o
	$(CC) $(CFLAGS) -o copyrecords copyrecords.o to_decode.o chi_sq.o encode.o encode_shift.o letter_count.o add_letters.o create_freq_table.o file_size.o -lm

decode: decode.o file_size.o chi_sq.o to_decode.o encode.o encode_shift.o letter_count.o add_letters.o create_freq_table.o
	gcc -ansi -Wall -o decode file_size.o to_decode.o decode.o chi_sq.o encode.o encode_shift.o letter_count.o add_letters.o create_freq_table.o -lm

file_size.o: file_size.c
	$(CC) $(CFLAGS) -c file_size.c

encode.o: encode.c
	$(CC) $(CFLAGS) -c encode.c

encode_shift.o: encode_shift.c
	$(CC) $(CFLAGS) -c encode_shift.c

chi_sq.o: chi_sq.c
	$(CC) $(CFLAGS) -c chi_sq.c

to_decode.o: to_decode.c
	$(CC) $(CFLAGS) -c to_decode.c

frequency_table:letter_count.o add_letters.o create_freq_table.o file_size.o
	$(CC) $(CFLAGS) frequency_table.c letter_count.o add_letters.o create_freq_table.o -o frequency_table file_size.o

letter_count.o: letter_count.c
	$(CC) $(CFLAGS) -c letter_count.c

add_letters.o: add_letters.c
	$(CC) $(CFLAGS) -c add_letters.c

create_freq_table.o: create_freq_table.c
	$(CC) $(CFLAGS) -c create_freq_table.c

clean:
	rm *o frequency_table decode copyrecords
