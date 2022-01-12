#include "funcs.h"

char ***create_alphabetical_array(char **words){
  int wordsLength=0;
  int i=0;
  int j=0;
  int k=0;

  while (words[wordsLength]!=NULL) wordsLength++;

  char ***alphabetical_array;
  alphabetical_array=malloc(26*sizeof(char **));

  for (i=0;i<26;i++){
    alphabetical_array[i]=malloc(wordsLength*sizeof(char *));
      for (j=0;j<wordsLength;j++){
        if (toupper(words[j][0])=='A'+i){
          alphabetical_array[i][k]=malloc(WORD_MAX *sizeof(char));
          strcpy(alphabetical_array[i][k],words[j]);
          k++;
        }
      }
    alphabetical_array[i][k]=NULL;
    k=0;
  }

  return alphabetical_array;
}
