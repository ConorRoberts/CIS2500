#include "h.h"

void sort1Print(Node *head){
  Node *p=head;

  while (p!=NULL){
    printf("%lf\t %lf\t %d\n",p->key1,p->key2,p->value);
    p=p->sort1;
  }
}
