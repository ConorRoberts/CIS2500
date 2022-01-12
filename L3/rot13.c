#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char rot(char c, int shift){
  if (c>='a' && c<='z'){
    c='a'+(((c-'a')+shift)%26);
    if (c<'a') c+=26;
  }else if (c>='A' && c<='Z'){
    c='A'+(((c-'A')+shift)%26);
    if (c<'A') c+=26;
  }
  return c;
}

int main(int argc, char *argv[]){

  char c;
  int i;
  FILE *in=NULL;
  FILE *out=NULL;

  char str[500];

  if (argc==1){ /*No arguments*/
      printf("Input: ");
      fgets(str,500,stdin);
      for(i=0;i<strlen(str);i++) str[i]=rot(str[i],13);
      printf("Output: %s",str);
  }else{
    if ((in=fopen(argv[1],"r"))!=NULL){
      if(argc==2){ /*Missing output file*/
        while((c=fgetc(in))!=EOF) /*Writes to stdout*/
            printf("%c",rot(c,13));
      }else if (argc==3){
        out=fopen(argv[2],"w"); /*Opens output file*/
        while((c=fgetc(in))!=EOF) /*Writes to file*/
          fputc(rot(c,13), out);
      }
    }
  }

  if (in!=NULL) fclose(in);
  if (out!=NULL) fclose(out);
  return 0;
}
