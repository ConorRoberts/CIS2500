#include "funcs.h"

void free_array(struct Double_Array *ptr){
  free(ptr->array);
  free(ptr);
  ptr=NULL;
}
