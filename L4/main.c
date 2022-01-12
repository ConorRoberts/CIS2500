#include "h.h"

int main(int argc, char *argv[]){
  int nodes;
  int i=1;

  do{
    printf("How many nodes? (>5) ");
    scanf("%d",&nodes);
  }while(nodes<5);

  Node *head=createList(nodes);
  Node *sort1_head=sort1(head);
  Node *sort2_head=sort2(head);
  Node *p=head;

  printList(head);
  printf("\n");
  sort1Print(sort1_head);
  printf("\n");
  sort2Print(sort2_head);
  printf("\n");

  while(p!=NULL){
    if (i%3==0){
      p->value*=10;
    }
    i++;
    p=p->next;
  }

  printList(head);

  freeList(head);
  return 0;
}
