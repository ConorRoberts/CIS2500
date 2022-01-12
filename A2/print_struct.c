#include "funcs.h"

void print_struct(struct Double_Array *ptr, char *str){
  printf("%s\n",str);
  printf("struct address = %p\n",(void *) ptr);
  printf("row_size = %d, col_size = %d\n",ptr->rowsize,ptr->colsize);
  printf("array address = %p, with contents:\n\n",(void *) ptr->array);

  print_array(ptr);
}
