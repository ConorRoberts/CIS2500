#include "functions.h"

int main(int argc, char *argv[]){

  FILE *in=NULL;

  int i=0,opt;
  int *counts;
  int flag=0;

  char tmp[LINE_SIZE],c;
  char *str=NULL;

  opterr=0;

  while((opt=getopt(argc,argv,"F:"))!=-1){
    if(opt=='F' && optarg!=NULL){ /*Input*/
      if ((in=fopen(optarg,"r"))==NULL){
        fprintf(stderr,"Error - Could not open file %s\n",argv[optind]);
        exit(0);
      }
    }else if(opt=='?'){
      fprintf(stderr,"Unknown option '-%c'\n",optopt);
      exit(0);
    }
  }

  if (in==NULL){ /*stdin -> stdout*/
    printf("Input: ");
    while(fgets(tmp,LINE_SIZE,stdin)!=NULL){
      if(!flag){
        flag=1;
        str=malloc(strlen(tmp));
        strcpy(str,tmp);
      }else{
        str=realloc(str,strlen(str)+strlen(tmp));
        strcat(str,tmp);
      }
    }
  }else if (in!=NULL){ /*file -> stdout*/
      str=malloc(file_size(in));
      while((c=fgetc(in))!=EOF)
        str[i++]=c;
  }

  counts=create_freq_table();
  add_letters(counts,str);

  printf("\nTotal Letters: %d\n",letter_count(str));
  printf("Total Characters: %ld\n",strlen(str)-1);
  printf("\nLetter \t Count\n");
  for (i=0;i<26;i++)
    printf("%c \t %d\n",'A'+i,counts[i]);

  free(counts);
  if (str!=NULL) free(str);
  if (in!=NULL) fclose(in);

  return 0;
}
