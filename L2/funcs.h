
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_LENGTH 20

struct foobarbaz{
  int foo;
  double bar;
  int baz;
};

double rand_double(double, double);
struct foobarbaz *rand_foobarbaz();
struct foobarbaz **many_foobarbaz();
void print_foobarbaz(struct foobarbaz **);
void swap_foobarbaz(struct foobarbaz **, int, int);
