#include "funcs.h"

int main(){

  srand(time(NULL));

  printf("---------------------------\n");
  printf("        Question 2a        \n");
  printf("---------------------------\n");

  struct Double_Array *a1=double_array(6,9);
  randomize_array(a1,0,10);
  printf("the address of a1 is %p\n",(void *) a1);
  print_struct(a1,"The structure pointed to by a1 is:");

  struct Double_Array *a2=a1;
  printf("the address of a1 is %p\n",(void *) a2);
  print_struct(a2,"The structure pointed to by a2 is:");

  struct Double_Array *a_shallow=shallow_copy(a1);
  printf("the address of a_shallow is %p\n",(void *) a_shallow);
  print_struct(a_shallow, "The structure pointed to by a_shallow is:");

  struct Double_Array *a_deep=deep_copy(a1);
  printf("the address of a_deep is %p\n",(void *) a_deep);
  print_struct(a_deep, "The structure pointed to by a_deep is:");

  printf("\n\n\n");

  printf("---------------------------\n");
  printf("        Question 2b        \n");
  printf("---------------------------\n");

  a1->array[0][1]=100;
  a2->array[1][2]=200;
  a_shallow->array[2][3]=300;
  a_deep->array[3][4]=400;

  print_struct(a1,"The structure pointed to by a1 is:");
  print_struct(a2,"The structure pointed to by a2 is:");
  print_struct(a_shallow, "The structure pointed to by a_shallow is:");
  print_struct(a_deep, "The structure pointed to by a_deep is:");

  printf("\n\n\n");

  printf("---------------------------\n");
  printf("        Question 2c        \n");
  printf("---------------------------\n");

  struct Double_Array *b1=double_array(6,9);
  randomize_array(b1,10,20);
  a2->array=b1->array;

  print_struct(a1,"The structure pointed to by a1 is:");
  print_struct(a2,"The structure pointed to by a2 is:");
  print_struct(a_shallow, "The structure pointed to by a_shallow is:");
  print_struct(a_deep, "The structure pointed to by a_deep is:");
  print_struct(b1, "The structure pointed to by b1 is:");

  a1->array[0][1]=5000;
  a2->array[1][2]=6000;
  a_shallow->array[2][3]=700;
  a_deep->array[3][4]=8000;
  b1->array[4][5]=9000;

  print_struct(a1,"The structure pointed to by a1 is:");
  print_struct(a2,"The structure pointed to by a2 is:");
  print_struct(a_shallow, "The structure pointed to by a_shallow is:");
  print_struct(a_deep, "The structure pointed to by a_deep is:");
  print_struct(b1, "The structure pointed to by b1 is:");

  free_array(a1);
  free_array(a_deep);

  return 0;
}
