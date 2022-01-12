#include <stdio.h>
#include <stdlib.h>
#include "Sorted_List.h"
#include "Recursion.h"
#include <string.h>

int main(int argc,char *argv[]){
  FILE *fp;
  if ((fp=fopen(argv[1],"r"))==NULL){
    fp=stdin;
  }

  Sorted_List *list=new_list();
  char command[COMMAND_SIZE];
  char buffer[100];
  char arg_1[25];
  char arg_2[25];

  value_type value;
  key_type key;

  while(fgets(buffer,100,fp)!=NULL){
    sscanf(buffer,"%s %s %s",command,arg_1,arg_2);
    strcat(command,":");
    if (!strcmp(command,"count_up:")){
      int n=atoi(arg_1);
      printf("%s from 0 to %d\n",command,n);
      count_up(n);
      printf("\n");
    }else if(!strcmp(command,"count_down:")){
      int n=atoi(arg_1);
      printf("%s from %d to 0\n",command,n*2);
      count_down(n);
      printf("\n");
    }else if(!strcmp(command,"nth:")){
      int n=atoi(arg_1);
      if (n>size(list)){
        printf("%s\tn = %d, FAILED, n>= size where size = %d\n",command,n,size(list));
      }else{
        printf("%s n = %d, %s\n",command,n,arg_2);
        if (!strcmp(arg_2,"INSERTED_ORDER")){
          find_n(list->head,n);
        }else if(!strcmp(arg_2,"SORTED_ORDER")){
          find_n_sorted(list->head_sort,n);
        }
    }
    }else if(!strcmp(command,"remove_nth:")){
      int n=atoi(arg_1);
      if (n>size(list)){
        printf("%s\tn = %d, FAILED, n>= size where size = %d\n",command,n,size(list));
      }else{
        printf("%s n = %d, %s\n",command,n,arg_2);
        if (!strcmp(arg_2,"INSERTED_ORDER")){
          remove_n(list,list->head,n);
        }else if(!strcmp(arg_2,"SORTED_ORDER")){
          remove_n_sorted(list,list->head_sort,n);
        }
    }
    }else{
      key=atof(arg_1);
      value=atoi(arg_2);
      command_q1a(command, list, value, key);
    }
  }

  fclose(fp);
  destroy_list(list);
  return SUCCESS;
}
