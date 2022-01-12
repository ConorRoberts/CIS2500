#include "functions.h"

int letter_count(char *str){
  int count=0,i;
  for(i=0;str[i]!='\0';i++)
    if (isalpha(str[i])) count++;
  return count;
}
