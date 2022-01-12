#include "funcs.h"

int main(){

  printf("---------------------------\n");
  printf("        Question 1         \n");
  printf("---------------------------\n");

  srand(time(NULL));

  int row=6;
  int col=9;

  struct Double_Array *og=double_array(row,col);

  randomize_array(og,1,25);
  print_array(og);

  int a=rand()%row;
  int b=rand()%row;
  swap_rows(og,a,b);
  printf("Rows %d & %d were swapped.\n",a+1,b+1);
  print_array(og);

  a=rand()%col;
  b=rand()%col;
  swap_columns(og,a,b);
  printf("Columns %d & %d were swapped.\n",a+1,b+1);
  print_array(og);

  printf("\n\n\n");

  free_array(og);
  return 0;
}
