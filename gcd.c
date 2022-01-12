#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b) {
  while (b>0){
    int r=a%b;
    a=b;
    b=r;
  }
  return a;
}

long gcd(long a, long b){
  if (b>0){
    int r=a%b;
    a=b;
    b=r;
    gcd(a,b);
  }else{
    return a;
  }
}

int main(){
  printf("%d\n",GCD(426,6129));
  printf("%ld\n",new_GCD(426,6129));

  return 0;
}
