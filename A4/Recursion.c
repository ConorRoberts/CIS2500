#include "Recursion.h"
#include <string.h>
#include "Sorted_List.h"

void count_up(int n){
  if (n>0){
    count_up(n-1);
    printf("%d, ",n);
  }
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

void count_down(int n){
  if(n>=0){
    printf("%d, ",2*n);
    count_down(n-1);
  }
}

void find_n(Node *p, int n){
    if (n>0){
      find_n(p->next, n-1);
    }else{
      printf("\t%lf %d\n",p->key,p->value);
    }
}

void find_n_sorted(Node *p, int n){
  if (n>0){
    find_n(p->sort, n-1);
  }else{
    printf("\t%lf %d\n",p->key,p->value);
  }
}

void remove_n(Sorted_List *list, Node *p, int n){
  if (n>0){
    remove_n(list,p->next, n-1);
  }else{
    printf("\t%lf %d\n",p->key,p->value);
    remove_node(list,p);
  }
}

void remove_n_sorted(Sorted_List *list, Node *p, int n){
  if (n>0){
    remove_n_sorted(list,p->sort, n-1);
  }else{
    printf("\t%lf %d\n",p->key,p->value);
    remove_node(list,p);
  }
}
