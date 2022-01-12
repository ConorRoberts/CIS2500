#include "funcs.h"

void swap_foobarbaz(struct foobarbaz **arr, int a, int b){
  struct foobarbaz *tmp=(struct foobarbaz *) malloc(sizeof(struct foobarbaz));

  tmp=arr[a];
  arr[a]=arr[b];
  arr[b]=tmp;
}
