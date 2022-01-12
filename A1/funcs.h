#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORD_MAX 45

char **read_words(FILE *);
void print_words(char **);
int *alphabetical_word_count(char **);
void print_alphabetical_word_count(int *);
char ***create_alphabetical_array(char **);
void free_alphabetical_array(char ***);
void printWordsAlphabetically(char ***);
int file_size(FILE *);
