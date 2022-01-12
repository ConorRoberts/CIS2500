#include "funcs.h"

struct Double_Array *deep_copy(struct Double_Array *ptr){
  struct Double_Array *ret=malloc(sizeof(struct DoubleArray *));
  ret->array=malloc(sizeof(ptr->array));

  ret->rowsize=ptr->rowsize;
  ret->colsize=ptr->colsize;

  int i,j;

  ret->array=malloc(sizeof(double **)*ptr->rowsize);

  for (i=0;i<ptr->rowsize;i++){
    ret->array[i]=malloc(sizeof(double *)*ptr->colsize);
    for (j=0;j<ptr->colsize;j++){
      ret->array[i][j]=ptr->array[i][j];
    }
  }

  return ret;
}
