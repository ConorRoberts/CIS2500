#include "h.h"

void freeList(Node *head){
  Node *p;
  while(head!=NULL){
      p=head;
      head=head->next;
      free(p);
   }
}
