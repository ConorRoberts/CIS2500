#include "funcs.h"

void printWordsAlphabetically(char ***words){
  int i,j,swaps;
  int k=0;
  char tmp[WORD_MAX];

  int *counts=malloc(26*sizeof(int));

  for (i=0;i<26;i++){
    while (words[i][k]!=NULL) k++;
    counts[i]=k;
    k=0;
  }

  for(i=0;i<26;i++){
    if (counts[i]>1){
      do{
        swaps=0;
        for(j=1;j<counts[i];j++){
          if (strcmp(words[i][j-1],words[i][j])>1){
            strcpy(tmp,words[i][j-1]);
            strcpy(words[i][j-1],words[i][j]);
            strcpy(words[i][j],tmp);
            swaps++;
          }
        }
      }while (swaps>1);
    }
  }

  for (i=0;i<26;i++){
    printf("\n'%c'\n",'A'+i);
    if (counts[i]==0){
      printf("There are no words that begin with the letter '%c'\n",'A'+i);
    }
    print_words(words[i]);
  }
}
