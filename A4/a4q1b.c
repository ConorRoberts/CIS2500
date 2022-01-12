#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Sorted_List.h"
#include "Function_Ptr.h"

int main(int argc, char *argv[]){
  FILE *fp;
  if ((fp=fopen(argv[1],"r"))==NULL){
    fp=stdin;
  }

  int i;
  char buffer[100];
  char command[COMMAND_SIZE];
  char arg_1[25];
  char arg_2[25];
  char arg_3[25];

  key_type key;
  value_type value;

  Sorted_List *list[10];
  for (i=0;i<10;i++){
    list[i]=new_list();
  }

  int list_1;
  int list_2;

  while(fgets(buffer,100,fp)!=NULL){
    for(i=0;i<strlen(buffer);i++){
      if (buffer[i]=='|' || buffer[i]==':'){
        buffer[i]=' ';
      }
    }
    sscanf(buffer,"%s %s %s %s",command,arg_1,arg_2,arg_3);
    if (!strcmp(arg_3,"INSERTED_ORDER")){
      value=INSERTED_ORDER;
    }else if(!strcmp(arg_3,"SORTED_ORDER")){
      value=SORTED_ORDER;
    }else{
      value=atoi(arg_3);
    }

    strcat(command,":");

    if (!strcmp(command,"sum:")){
      list_1=atoi(arg_1);
      list_2=atoi(arg_2);
      printf("sum: list = %d, result = %d\n",list_1,sum(list[list_1]));

    }else if (!strcmp(command,"diff:")){

      list_1=atoi(arg_1);
      list_2=atoi(arg_2);

      value_type *values=diff(list[list_1],list[list_2],value);

      printf("diff: list1 = %d, list2 = %d, %s\n",list_1,list_2,arg_3);
      print_array(values,size(list[list_1]));
      free(values);

    }else if (!strcmp(command,"square:")){
      list_2=key;
      list_1=atoi(arg_1);
      Sorted_List *tmp=square(list[list_1]);
      printf("square: list = %d\n",list_1);

      print_all(tmp);

      destroy_list(tmp);
    }else if (!strcmp(command,"sum_sq_d:")){
      list_1=atoi(arg_1);
      list_2=atoi(arg_2);
      value_type result=sum_of_sq_diff(list[list_1],list[list_2],value);
      printf("sum_sq_diff: list1 = %d, list2 = %d, %s, result = %d\n",list_1,list_2,arg_3,result);
    }else{
      list_1=atoi(arg_1);
      key=atof(arg_2);
      value=atoi(arg_3);
      if (!strcmp(command,"print_all:") || !strcmp(command,"print_sort:")){
        printf("List %d - ",list_1);
      }
      command_q1a(command, list[list_1], value, key);
    }
  }

  if (fp!=NULL) fclose(fp);
  for(i=0;i<10;i++){ /*Destroys all linked lists*/
    destroy_list(list[i]);
  }

  return 0;
}
