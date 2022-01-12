#include "funcs.h"

struct foobarbaz **many_foobarbaz(){

  struct foobarbaz **ptr=(struct foobarbaz **) malloc(ARRAY_LENGTH*sizeof(struct foobarbaz *));

  int i;

  for (i=0;i<ARRAY_LENGTH;i++){
    ptr[i]=malloc(sizeof(struct foobarbaz));

    ptr[i]->foo=(int) rand_double(0,49);
    ptr[i]->bar=rand_double(0,100);
    ptr[i]->baz= (int) rand_double(50,99);
  }

  return ptr;
}
