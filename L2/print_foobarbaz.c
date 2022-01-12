#include "funcs.h"

void print_foobarbaz(struct foobarbaz **ptr){
  int i;
  for (i=0;i<ARRAY_LENGTH;i++){
    printf("%d\t%g\t\t%d\n",ptr[i]->foo,ptr[i]->bar,ptr[i]->baz);
  }
}
