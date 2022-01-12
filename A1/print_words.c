#include "funcs.h"

void print_words(char **words){
  int i=0;
  while(words[i]!=NULL){
    printf("%s\n",words[i++]);
  }
}
