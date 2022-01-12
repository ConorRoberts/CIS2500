#include "funcs.h"

void print_alphabetical_word_count(int *counts){
  int i;
  for(i=0;i<26;i++){
    printf("%c = %d, ",'A'+i,counts[i]);
  }printf("\n");
}
