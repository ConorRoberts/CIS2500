#include "functions.h"

double chi_sq(char *str,int shift){
  double ef[26]=EF;
  int n=letter_count(str);

  int i;
  double sum=0;

  int *freq=create_freq_table();
  add_letters(freq,str);

  for (i=0;i<26;i++){
    char c=encode('A'+i,shift);
    if (c>'Z') c-='A';

    sum+=pow(n*ef[i]-freq[c-'A'],2)/(n*n*ef[i]);
  }

  free(freq);

  return sum;
}
