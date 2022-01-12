#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <getopt.h>
#include <limits.h>

struct record{
  char str1[24];
  double doubles[24];
  char str2[144];
  int ints[12];
};

#define LINE_SIZE 10000

#define EF {0.08167,0.01492,0.02782,0.04253,0.12702,0.02228,0.02015,0.06094,0.06966,0.00153,0.00722,0.04025,0.02406,0.06749,0.07707,0.01929,0.00095,0.05987,0.06327,0.09056,0.02758,0.00978,0.02360,0.00150,0.01974,0.00074}

/*Counts letters in a given string and returns int*/
int letter_count(char *);

/*Creates integer array containing 26 0s*/
int *create_freq_table();

/*Counts occurrences of letters in a given string*/
void *add_letters(int *,char *);

/*Caesar cipher shifter. Takes in character and shifts by 'shift' amount*/
char encode(char, int);

/*Returns the shift necessary to decode a given string*/
int encode_shift(char *);

/*Computes shift required to decode an encoded string*/
int to_decode(int);

/*Computes chi_sq value for a given string*/
double chi_sq(char *, int);

/*Computes maximum number of characters in file*/
int file_size(FILE *);
