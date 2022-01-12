#include "funcs.h"

struct foobarbaz *rand_foobarbaz(){
  struct foobarbaz *ptr=(struct foobarbaz *) malloc(sizeof(struct foobarbaz));

  ptr->foo= (int) rand_double(0,49);
  ptr->bar= rand_double(0,100);
  ptr->baz= (int) rand_double(50,99);

  return ptr;
}
