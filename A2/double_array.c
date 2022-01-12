#include "funcs.h"

struct Double_Array *double_array(int row, int col){

  int i;

  struct Double_Array *ptr=malloc(sizeof(struct DoubleArray *));

  ptr->array=malloc(sizeof(double **)*row);
  for(i=0;i<row;i++){
      ptr->array[i]=malloc(sizeof(double *)*col);
  }

  ptr->rowsize=row;
  ptr->colsize=col;

  return ptr;
}
