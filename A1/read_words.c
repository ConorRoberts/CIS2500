#include "funcs.h"

char **read_words(FILE *fp){
  char p[WORD_MAX];
  int j;

  char **words=malloc(file_size(fp)*sizeof(char *));

  int i=0;

  while (fscanf(fp,"%s",p)==1){
    words[i]=malloc(WORD_MAX*sizeof(char));
    for(j=0;j<strlen(p);j++){
      p[j]=tolower(p[j]);
    }
    strcpy(words[i],p);
    i++;
  }

  words[i]=NULL;

  return words;
}
