#include "funcs.h"

int swap_rows (struct Double_Array *ptr, int a, int b){

  if(a>ptr->rowsize || a<0 || b<0 || b>ptr->rowsize){
    return 0;
  }else{
    double *tmp=malloc(sizeof(double)*ptr->colsize);

    /*Q1a
      Entire rows can be indexed by just using the first coordinate in the 2D array 
      This saves time because we don't need to individually copy every element with a for loop
    */
    tmp=ptr->array[a];
    ptr->array[a]=ptr->array[b];
    ptr->array[b]=tmp;

    return 1;
  }
}
