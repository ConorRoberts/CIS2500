#include "funcs.h"

void free_alphabetical_array(char ***words){

  int k=0;
  int i,j;
  int *counts=malloc(26*sizeof(int));

  for (i=0;i<26;i++){
    while (words[i][k]!=NULL) k++;
    counts[i]=k;
    k=0;
  }

  for (i=0;i<26;i++){
    for (j=0;j<counts[i];j++){
      free(words[i][j]);
    }
  }

  free(words);
}
