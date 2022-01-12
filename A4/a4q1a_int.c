#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "Sorted_List.h"

int main(int argc, char *argv[]){
  FILE *fp;
  if ((fp=fopen(argv[1],"r"))==NULL){
    fp=stdin;
  }

  Sorted_List *list=new_list();
  char command[COMMAND_SIZE];
  char buffer[100];

  value_type value;
  key_type key;

  while(fgets(buffer,100,fp)!=NULL){
    sscanf(buffer,"%s %lf %d",command,&key,&value);
    strcat(command,":");
    command_q1a(command, list, value, key);
  }

  fclose(fp);
  destroy_list(list);
  return SUCCESS;
}
