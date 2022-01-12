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
  Node *p1=head;
  Node *tmp;
  Node *p3;
  Node *sort1_head=NULL;
  int i;
  int nodes=0;
  double min=INT_MAX;

  /*Finds smallest and saves address as newHead*/
  while (p1->next!=NULL){
    if (p1->key1<min){
       sort1_head=p1;
       min=sort1_head->key1;
    }
    p1=p1->next;
    nodes++; /*Counts nodes in list*/
  }

  p3=sort1_head;
  for(i=1;i<nodes;i++){
    min=INT_MAX;
    p1=head;

    while (p1->next!=NULL){
      /*Checks for a minimum that isn't already in the list*/
      if(!sort1Check(sort1_head,p1) && p1->key1<min){
        min=p1->key1;
        tmp=p1;
      }

      p1=p1->next;
    }

    p3->sort1=tmp;
    p3=p3->sort1;
  }

  return sort1_head;
}
