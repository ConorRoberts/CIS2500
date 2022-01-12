#include "funcs.h"

int *alphabetical_word_count(char **words){
  int *counts=malloc(26*sizeof(int));
  int k=0,i=0,j=0;

  for(i=0;i<26;i++){
    while(words[j]!=NULL){
      if (toupper(words[j][0])==(i+'A')) k++;
      j++;
    }
    counts[i]=k;
    k=0;
    j=0;
  }

  return counts;
}
