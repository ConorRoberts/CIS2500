#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define LINE_LENGTH 2048
#define LINE_MAX 2048

int main(){
  char line[LINE_LENGTH];
  int totalWords=0,lineCount=0,i=0,j,k,flag,wordCount=0;
  int arrLength[LINE_MAX];
  char wordList[LINE_MAX][LINE_LENGTH];

  printf("Enter the poem:\n");

  do{
      j=0;
      flag=0;

      fgets(line,LINE_LENGTH,stdin);
      line[strlen(line)-1]='\0';

      if (!strcmp(line,".")) continue;

      /*Putting words into array*/
      char *p=strtok(line," ");
      while(p !=NULL){
          strcpy(wordList[j++],p);
          p=strtok(NULL," ");
      }

      /*Counting word elements comprised of only alphabetic characters*/
      for (i=0;i<j;i++){
        flag=0;
        for (k=0;k<strlen(wordList[i]);k++){
          if (!isalpha(wordList[i][k])) flag=1;
        }
        if (flag==0){
          wordCount++;
        }
      }

      arrLength[lineCount]=wordCount;

      totalWords+=wordCount;
      wordCount=0;
      lineCount++;
  }while (strcmp(line,"."));

  printf("%d words on %d lines\n",totalWords,lineCount);
  for (i=0;i<lineCount;i++){
    printf("%d ",arrLength[i]);
  }printf("\n");
}
