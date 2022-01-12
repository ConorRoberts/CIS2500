#include "Sorted_List.h"
#include <string.h>

void command_q1a(char command[COMMAND_SIZE], Sorted_List *list, value_type value, key_type key){
  int to_print=0;
  int remove_print=0;

  value_type value_return;
  key_type key_return;

  if (!strncmp(command,"a:",2)){
    append(list,value,key);
    to_print=1;
  }else if (!strncmp(command,"p:",2)){
    push(list,value,key);
    to_print=1;
  }else if(!strncmp(command,"rem_first",strlen("rem_first"))){
    remove_first(list,&value_return,&key_return);
    remove_print=1;
  }else if(!strncmp(command,"rem_last",strlen("rem_last"))){
    remove_last(list,&value_return,&key_return);
    remove_print=1;
  }else if(!strncmp(command,"rem_small",strlen("rem_small"))){
    remove_smallest_key(list,&value_return,&key_return);
    remove_print=1;
  }else if(!strncmp(command,"rem_large",strlen("rem_large"))){
    remove_largest_key(list,&value_return,&key_return);
    remove_print=1;
  }else if(!strncmp(command,"empty",strlen("empty"))){
    empty_list(list);
  }else if(!strncmp(command,"print_all",strlen("print_all"))){
    printf("print_all: Insertion order\n");
    print_all(list);
  }else if(!strncmp(command,"print_sort",strlen("print_sort"))){
    printf("print_sort: Sorted order\n");
    print_sort(list);
  }else if (!strncmp(command,"size",strlen("size"))){
    printf("size: List size = %d\n",size(list));
  }

  if (to_print){
    #ifdef CHAR
    printf("%s\t%d  %s\n",command,key,value);
    #endif

    #ifdef INT
    printf("%s\t%lf  %d\n",command,key,value);
    #endif
  }else if(remove_print){
    #ifdef CHAR
    printf("%s\t%d  %s\n",command,key_return,value_return);
    #endif

    #ifdef INT
    printf("%s\t%lf  %d\n",command,key_return,value_return);
    #endif
  }
}

void print_all(Sorted_List *list){
  Node *p;

  #ifdef INT
  for(p=list->head;p!=NULL;p=p->next){
    printf("\t%lf %d\n",p->key,p->value);
  }
  #endif
  #ifdef CHAR
  for(p=list->head;p!=NULL;p=p->next){
    printf("\t%d %s\n",p->key,p->value);
  }
  #endif
}

void print_sort(Sorted_List *list){
  Node *p;

  sort_list(list);

  #ifdef INT
  for(p=list->head_sort;p!=NULL;p=p->sort){
    printf("\t%lf %d\n",p->key,p->value);
  }
  #endif
  #ifdef CHAR
  for(p=list->head_sort;p!=NULL;p=p->sort){
    printf("\t%d %s\n",p->key,p->value);
  }
  #endif
}

Sorted_List *new_list(){
    Sorted_List *list=(Sorted_List *) calloc(1,sizeof(Sorted_List));
    list->head=NULL;
    list->head_sort=NULL;
    list->tail=NULL;
    list->tail_sort=NULL;
    list->size=0;
    return list;
}

void empty_list (Sorted_List *list){
  Node *p;
  while(list->head!=NULL){
      p=list->head;
      list->head=list->head->next;
      free(p);
   }
   list->size=0;
}

void destroy_list (Sorted_List *list){
  empty_list(list);
  free(list);
}

int remove_last (Sorted_List *list, value_type *value, key_type *key){
  if (list->size==0){
    return FAIL;
  }

  Node *p=list->tail;
  *key=p->key;

  #ifdef INT
    *value=p->value;
  #endif

  #ifdef CHAR
    strcpy(*value,p->value);
  #endif

  remove_node(list,list->tail);

  return SUCCESS;
}

int remove_first (Sorted_List *list, value_type *value, key_type *key){
  if (list->size==0){
    return FAIL;
  }

  Node *p=list->head;
  *key=p->key;

  #ifdef INT
    *value=p->value;
  #endif

  #ifdef CHAR
    strcpy(*value,p->value);
  #endif

  remove_node(list,list->head);

  return SUCCESS;
}

int push (Sorted_List *list, value_type value, key_type key){

  Node *p=(Node *) calloc(1,sizeof(Node));

  #ifdef INT
    p->value=value;
    p->key=key;
  #endif

  #ifdef CHAR
    strcpy(p->value,value);
    p->key=key;
  #endif

  if(list->tail==NULL && list->head==NULL){
    list->tail=p;
    list->head=p;
  }else{
    list->head->prev=p;
    p->next=list->head;
    list->head=p;
  }

  list->size=size(list);

  sort_list(list);

  return SUCCESS;
}

int append (Sorted_List *list, value_type value, key_type key){
  Node *p=(Node *) calloc(1,sizeof(Node));

  #ifdef INT
    p->value=value;
    p->key=key;
  #endif

  #ifdef CHAR
    strcpy(p->value,value);
    p->key=key;
  #endif

  #ifdef FRACT
    
  #endif

  if(list->tail==NULL && list->head==NULL){
    list->tail=p;
    list->head=p;
  }else{
    list->tail->next=p;
    p->prev=list->tail;
    list->tail=p;
  }

  list->size=size(list);

  sort_list(list);

  return SUCCESS;
}

void remove_node(Sorted_List *list, Node *p){

  /*Adjust surrounding next/prev links*/
  if (p->prev!=NULL){
    p->prev->next=p->next;
  }else{
    list->head=p->next;
  }
  if (p->next!=NULL){
    p->next->prev=p->prev;
  }else{
    list->tail=p->prev;
  }

  free(p);

  list->size=size(list);

  /*Adjust sort links*/
  sort_list(list);
}

int remove_largest_key (Sorted_List *list, value_type *value, key_type *key){
  if (list->size==0){
    return FAIL;
  }

  Node *p;
  Node *max_key=list->head;
  key_type max=list->head->key;

  /*Finds largest key value*/
  for(p=list->head;p!=NULL;p=p->next){
    if(p->key>max){
      max_key=p;
      max=p->key;
    }
  }

  /*Returns values to variables given*/
  #ifdef INT
    *value=max_key->value;
  #endif

  #ifdef CHAR
    strcpy(*value,max_key->value);
  #endif
  *key=max_key->key;

  remove_node(list,max_key);

  return SUCCESS;
}

int remove_smallest_key (Sorted_List *list, value_type *value, key_type *key){
  if (list->size==0){
    return FAIL;
  }

  Node *p;
  Node *min_key=list->head;
  key_type min=list->head->key;

  /*Finds smallest key value*/
  for(p=list->head;p!=NULL;p=p->next){
    if(p->key>min){
      min_key=p;
      min=p->key;
    }
  }

  /*Returns values to variables given*/
  #ifdef INT
    *value=min_key->value;
  #endif

  #ifdef CHAR
    strcpy(*value,min_key->value);
  #endif
  *key=min_key->key;

  remove_node(list,min_key);

  return SUCCESS;
}

int size (Sorted_List *list){
  Node *p;
  int size=0;

  for (p=list->head;p!=NULL;p=p->next){
    size++;
  }

  return size;
}

/*Checks the linked list for a duplicate node*/
int check_list(Node *head, Node *node){
  Node *p;
  for(p=head;p!=NULL;p=p->sort){
    if (p==node){
      return 1;
    }
  }
  return 0;
}

/*Finds the minimum value in the linked list and returns the Node with such value*/
Node *find_head(Sorted_List *list){
  Node *sort_head;
  Node *p;
  double min=INT_MAX;
  for(p=list->head;p!=NULL;p=p->next){
    if (p->key<min){
       sort_head=p;
       min=sort_head->key;
    }
  }

  sort_head->prev_sorted=NULL;
  return sort_head;
}

/*Unlinks all sort links*/
void reset_links(Sorted_List *list){
  Node *p;
  for(p=list->head;p!=NULL;p=p->next){
    p->sort=NULL;
  }
}

/*Assigns the head_sort Node on a given sorted list*/
void sort_list(Sorted_List *list){

    reset_links(list);

    Node *p;
    Node *node;
    int i;
    double min=INT_MAX;

    list->head_sort=find_head(list);
    Node *sort_ptr=list->head_sort;
    Node *prev=list->head_sort;
    /*Links nodes to head*/
    for(i=1;i<list->size;i++){
      min=INT_MAX;
      for(p=list->head;p!=NULL;p=p->next){
        if(!check_list(list->head_sort,p) && p->key<=min){
          min=p->key;
          node=p;
        }
      }
      sort_ptr->prev_sorted=prev; /*Assigns previous node*/
      sort_ptr->sort=node; /*Assigns next node*/

      prev=node; /*Moves prev to current node*/
      sort_ptr=sort_ptr->sort; /*Traverses to next node*/
    }
    sort_ptr->sort=NULL;
    list->tail_sort=sort_ptr;
}
