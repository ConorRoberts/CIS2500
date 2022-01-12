#include "Fractions.h"
#include "Recursion.h"
#include <stdio.h>

int set_fraction(Fraction *frac, long long num, long long denom){
  if (denom==0){
    return FALSE;
  }

  if (denom<0){
    num*=-1;
    denom*=-1;
  }

  frac->num=num;
  frac->denom=denom;

  return TRUE;
}

void print_fract (Fraction *frac, int mode){
  if (mode==SIMPLE){
    printf("%lld/%lld\n",frac->num,frac->denom);
  }else if(mode==MIXED){
    int n=0;
    if (frac->num>frac->denom && frac->denom!=1){
      while(frac->num>frac->denom){
        frac->num-=frac->denom;
        n++;
      }
    printf("%d %lld/%lld\n",n,frac->num,frac->denom);
    }else if(frac->denom==1){
      printf("%lld\n",frac->num);
    }else{
        printf("%lld/%lld\n",frac->num,frac->denom);
    }
  }
}

void simplify(Fraction *frac){
  long g=gcd(frac->num,frac->denom);
  frac->num/=g;
  frac->denom/=g;
}

int add_fract(Fraction *frac_out, Fraction *frac_1, Fraction *frac_2){
  long a=frac_2->num;
  long b=frac_1->denom;
  long c=frac_2->num;
  long d=frac_2->denom;
  long result=((a*b)+(b*c))/(b*d);

  return result;
}
