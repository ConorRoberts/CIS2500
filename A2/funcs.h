#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Double_Array{
  double **array;
  int rowsize;
  int colsize;
};

struct Double_Array *double_array(int row, int col);
double rand_double(double, double);
void randomize_array(struct Double_Array *,double, double);
void print_array(struct Double_Array *);
void free_array(struct Double_Array *);
int swap_rows(struct Double_Array *,int, int);
int swap_columns(struct Double_Array *,int,int);
struct Double_Array *shallow_copy(struct Double_Array *);
struct Double_Array *deep_copy(struct Double_Array *);
void print_struct(struct Double_Array *, char *);
