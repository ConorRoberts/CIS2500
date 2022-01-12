#include "funcs.h"

void randomize_array(struct Double_Array *ptr, double a, double b){
  int i,j;
  for (i=0;i<ptr->rowsize;i++){
    for (j=0;j<ptr->colsize;j++){
      ptr->array[i][j]=rand_double(a,b);
    }
  }
}
