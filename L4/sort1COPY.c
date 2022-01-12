#include "h.h"

int sort1Check(Node *head, Node *p){
  Node *ptr=head;
  while(ptr!=NULL){
    if (ptr==p)
      return 1;
    ptr=ptr->sort1;
  }

  return 0;
}

Node *sort1(Node *head){
  Node *i=head;
  Node *j=head;
  Node *k;
  Node *p3;
  int flag=0;
  Node *sort1_head=NULL;
  double min=INT_MAX;

  /*Finds smallest and saves address as newHead*/
  while (i->next!=NULL){
    while (j->next!=NULL){
    while (!flag){

      } (i->key1<min)
       sort1_head=i;
       min=sort1_head->key1;
    }
    i=i->next;

    min=INT_MAX;
    i=head;

    while (i->next!=NULL){
      /*Checks for a minimum that isn't already in the list*/
      if(!sort1Check(sort1_head,i) && i->key1<min){
        min=i->key1;
        k=i;
      }

      i=i->next;
    }

    p3->sort1=k;
    p3=p3->sort1;
  }

  return sort1_head;
}
