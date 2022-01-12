#include "h.h"

double rand_double(double a, double b){

  if (a>b){
    int tmp=a;
    a=b;
    b=tmp;
  }

  return ((double) rand() / (double) RAND_MAX) * (b-a) + a;
}
