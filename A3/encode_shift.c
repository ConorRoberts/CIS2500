#include "functions.h"

int encode_shift(char *str){ /*Returns shift used to encode text*/
  if (strlen(str)<200)
    return 0;

  int min=INT_MAX;
  int shift,i;

  for(i=0;i<26;i++){
    int n=chi_sq(str,i);
    if(n<min){
      min=n;
      shift=i;
    }
  }

  if (min>=0.5){
    return 0;
  }else{
    return shift;
  }
}
