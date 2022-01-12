#include "funcs.h"

void print_array(struct Double_Array *ptr){
  int i,j;
  for (i=0;i<ptr->rowsize;i++){
    for (j=0;j<ptr->colsize;j++){
      printf("%6.1lf ",ptr->array[i][j]);
    }
    printf("\n");
  }
}
