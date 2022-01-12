#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  char c;
  FILE *in=NULL;
  FILE *out=NULL;

  char str[500];

  if (argc==1){ /*No arguments*/
      printf("Input: ");
      fgets(str,500,stdin);
      printf("Output: %s",str);
  }else{
    if ((in=fopen(argv[1],"r"))!=NULL){
      if(argc==2){ /*Missing output file*/
        while((c=fgetc(in))!=EOF) /*Writes to stdout*/
            printf("%c",c);
      }else if (argc==3){
        out=fopen(argv[2],"w"); /*Opens output file*/
        while((c=fgetc(in))!=EOF) /*Writes to file*/
          fputc(c, out);
      }
    }
  }

  if (in!=NULL) fclose(in);
  if (out!=NULL) fclose(out);

  return 0;
}
