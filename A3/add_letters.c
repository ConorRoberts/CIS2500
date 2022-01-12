#include "functions.h"

void *add_letters(int *intArr,char *str){

  int i;

  for (i=0;i<strlen(str);i++){
    if (toupper(str[i])>='A' && toupper(str[i])<='Z')
      intArr[toupper(str[i])-'A']++;
  }

  return intArr;
}
