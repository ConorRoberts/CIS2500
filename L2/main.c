#include "funcs.h"

int main(){

  int i;

  srand(time(NULL));

  struct foobarbaz **foob=many_foobarbaz();

  print_foobarbaz(foob);

  int a=rand()%20;
  int b=rand()%20;
  printf("\nSwapping positions %d & %d\n",a+1,b+1);

  swap_foobarbaz(foob,a,b);

  printf("\n");

  print_foobarbaz(foob);

  for (i=0;i<20;i++){
    free(foob[i]);
  }

  return 0;
}
