#include "functions.h"

void printStruct(struct record r){
  int i;
  printf("%s\n",r.str1);
  for (i=0;i<24;i++)
      printf("%lf, ",r.doubles[i]);

  printf("\n%s\n",r.str2);
  for (i=0;i<12;i++)
      printf("%d, ",r.ints[i]);
  printf("\n\n");
}

int main(int argc, char *argv[]){

  FILE *in=NULL;
  FILE *out=NULL;
  FILE *companion=NULL;

  int decodeShift=0;
  int r_flag=0;

  char *str=NULL;
  char c;
  int i=0;

  struct record r;

  int opt;
  opterr=0;

  while((opt=getopt(argc,argv,"F:O:D:r"))!=-1){ /*Reading command line arguments*/
    if(opt=='F' && optarg!=NULL){
      if ((in=fopen(optarg,"rb"))==NULL){
        fprintf(stderr,"Error - Could not open file %s\n",optarg);
        exit(0);
      }
    }else if (opt=='O' && optarg!=NULL){
          out=fopen(optarg,"wb");
    }else if (opt=='D' && optarg!=NULL){ /*Name of .txt file containing text used to find a shift*/
      if ((companion=fopen(optarg,"r"))==NULL){
        fprintf(stderr,"Error - Could not open file %s\n",optarg);
        exit(0);
      }
      str=(char *) malloc(file_size(companion));

      while((c=fgetc(companion))!=EOF) /*Adds file text to str*/
        str[i++]=c;

      decodeShift=to_decode(encode_shift(str));
    }else if (opt=='r'){ /*Reverse*/
      r_flag=1;
    }else if(opt=='?'){
      fprintf(stderr,"Unknown option '-%c'\n",optopt);
    }
  }

  if (in==NULL){ /*No input file present*/
    fprintf(stderr,"Input file not present.\n");
    exit(0);
  }else if (in!=NULL && r_flag){ /*FILE -> FILE/STDOUT (REVERSED)*/
   fseek(in, -sizeof(struct record), SEEK_END);
   int fileEnd=ftell(in);

    while(fread(&r, sizeof(struct record), 1, in)==1 && fileEnd>=0){
      for (i=0;r.str1[i]!='\0';i++){ /*Decodes STR1*/
        r.str1[i]=encode(r.str1[i],decodeShift);
      }

      for (i=0;r.str2[i]!='\0';i++){ /*Decodes STR2*/
        r.str2[i]=encode(r.str2[i],decodeShift);
      }


      if (out==NULL){
        printStruct(r);
      }else{
        fwrite(&r, sizeof(struct record), 1, out);
      }

      fseek(in, -2*sizeof(struct record), SEEK_CUR);
      fileEnd-=sizeof(struct record);
    }

  }else if (in!=NULL && !r_flag){ /*FILE -> FILE/STDOUT (NOT REVERSED)*/
    while(fread(&r,sizeof(struct record),1,in)==1){
      for (i=0;r.str1[i]!='\0';i++){ /*Decodes STR1*/
        r.str1[i]=encode(r.str1[i],decodeShift);
      }

      for (i=0;r.str2[i]!='\0';i++){ /*Decodes STR2*/
        r.str2[i]=encode(r.str2[i],decodeShift);
      }

      if (out==NULL){
        printStruct(r);
      }else{
        fwrite(&r, sizeof(struct record), 1, out);
      }
    }
  }

  if (str!=NULL) free(str);
  if (in!=NULL) fclose(in);
  if (out!=NULL) fclose(out);
  if (companion!=NULL) fclose(companion);
  return 0;
}
