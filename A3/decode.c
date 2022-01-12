#include "functions.h"

int main(int argc, char *argv[]){

  FILE *in=NULL;
  FILE *out=NULL;

  int fileSize;

  int i=0;
  char c;

  char *str;
  char tmp[LINE_SIZE];

  int flag=0;
  int n_flag=0;
  int S_flag=0;
  int x_flag=0;
  int s_flag=0;
  int t_flag=0;

  int opt;
  opterr=0;

  while((opt=getopt(argc,argv,"F:O:Sstxn"))!=-1){
    if(opt=='F' && optarg!=NULL){ /*Input*/
      if ((in=fopen(optarg,"r"))==NULL){
        fprintf(stderr,"Error - Could not open file %s\n",optarg);
        exit(0);
      }
      while((c=fgetc(in))!=EOF)
        fileSize++;
      rewind(in);
    }else if (opt=='O' && optarg!=NULL){/*Output*/
          out=fopen(optarg,"w");
    }else if (opt=='s'){ /*Computes shift to DECODE message*/
      s_flag=1;
    }else if (opt=='n'){
      n_flag=1;
    }else if (opt=='t'){
      t_flag=1;
    }else if (opt=='x'){
      x_flag=1;
    }else if (opt=='S'){ /**/
      S_flag=1;
    }else if(opt=='?'){
      fprintf(stderr,"Unknown option '-%c'\n",optopt);
    }
  }

  if (in==NULL){ /*Reads from stdin*/
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
  }else if (in!=NULL){ /*Reads from file*/
      str=malloc(file_size(in));
      while((c=fgetc(in))!=EOF)
        str[i++]=c;
  }

  int decodeShift=to_decode(encode_shift(str));

  if (S_flag){
    printf("Original shift: %d.\n",encode_shift(str));
  }

  if (s_flag){
    printf("Shift to decode: %d.\n",to_decode(encode_shift(str)));
  }

  if(out!=NULL){ /*Writes to file with -O flag*/
    rewind(in);
    while((c=fgetc(in))!=EOF)
      fputc(encode(c,decodeShift),out);
  }

  if (x_flag){ /*Prints all chi_sq values*/
    printf("Shift\tChi_Sq\n");
    for (i=0;i<26;i++){
      printf("%d\t%lf\n",i,chi_sq(str,i));
    }
  }

  if (t_flag){/*Prints frequency table*/
    int *freq=create_freq_table();
    add_letters(freq,str);
    printf("\nTotal Letters: %d\n",letter_count(str));
    printf("Total Characters: %ld\n",strlen(str)-1);
    printf("\nLetter \t Count\n");
    for (i=0;i<26;i++) printf("%c \t %d\n",'A'+i,freq[i]);
    free(freq);
  }

  if (out==NULL && !n_flag){ /*Prints decoded string if no -O is specified*/
    for (i=0;i<strlen(str);i++){
      str[i]=encode(str[i],decodeShift);
    }
    printf("\n%s\n",str);
  }

  free(str);
  if (in!=NULL) fclose(in);
  if (out!=NULL) fclose(out);
  return 0;
}
