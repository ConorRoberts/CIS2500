#include "funcs.h"

int swap_columns(struct Double_Array *ptr,int a, int b){
  if(a>ptr->colsize || a<0 || b<0 || b>ptr->colsize){
    return 0;
  }else{
    int i;
    double tmp;

    /* Q1b
    Columns cannot be indexed by using only one coordinate because
    each element in a column is stored in a different element of the
    first layer of the array
    */
    for(i=0;i<ptr->rowsize;i++){
      tmp=ptr->array[i][a];
      ptr->array[i][a]=ptr->array[i][b];
      ptr->array[i][b]=tmp;
    }

    return 1;
  }
}
