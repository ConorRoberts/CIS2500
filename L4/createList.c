#include "h.h"

Node *createList(int n){
  Node *head=malloc(sizeof(Node));
  Node *p=head;

  srand(time(NULL));
  int i;
  for (i=0;i<n;i++){
    p->value=rand_double(0,10);
    p->key1=rand_double(10,50);
    p->key2=rand_double(50,90);
    p->sort1=NULL;
    p->sort2=NULL;
    p->next=malloc(sizeof(Node));
    p=p->next;
  }

  return head;
}
