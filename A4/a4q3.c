#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "Sorted_List.h"
#include "Fractions.h"
#include "Recursion.h"

int main(int argc, char *argv[]){
  FILE *fp;
  if ((fp=fopen(argv[1],"r"))==NULL){
    fp=stdin;
  }

  Sorted_List *list=new_list();
  char command[COMMAND_SIZE];
  char buffer[100];

  char arg_1[25];
  char arg_2[25];

  while(fgets(buffer,100,fp)!=NULL){
    sscanf(buffer,"%s %s %s",command,arg_1,arg_2);
    printf("( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°) ͡°)\n");
  }

  fclose(fp);
  destroy_list(list);
  return SUCCESS;
}
