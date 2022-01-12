#include "h.h"

void printList(Node *head){
  Node *p=head;

  while (p->next!=NULL){
    printf("%lf\t %lf\t %d\n",p->key1,p->key2,p->value);
    p=p->next;
  }
}
