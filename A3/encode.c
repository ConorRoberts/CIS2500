#include "functions.h"

char encode(char c, int shift){
  /*Processes shift*/
  if (isalpha(c)){
    char t=toupper(c);
    t+=shift;
    if (t<'A'){
      t+=26;
    }else if(t>'Z'){
      t-=26;
    }

    /*Maintains case*/
    if (islower(c)){
      t=tolower(t);
    }else if (isupper(c)){
      t=toupper(t);
    }
    return t;
  }else{
    return c;
  }
}
