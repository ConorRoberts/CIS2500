#include "Sorted_List.h"
#include "Function_Ptr.h"

Sorted_List *filter(Sorted_List *list, int (*fn)()){
 Node *p;
 Sorted_List *new = new_list();
 for (p=list->head;p!=NULL;p=p->next){
   if (fn(p->value)==TRUE){
     append(new, p->value, p->key);
   }
 }
 return new;
}

void print_array(value_type *value, int size){
  int i;
  for(i=0;i<size;i++){
    printf("     %d\n",value[i]);
  }
}

Sorted_List *map (Sorted_List *list, value_type (*fn)()){
  Sorted_List *ptr_list=new_list();
  Node *node;

  for (node=list->head;node!=NULL;node=node->next){
    append(ptr_list,fn(node->value),node->key);
  }

  return ptr_list;
}

value_type fn_add(value_type x, value_type y){
  return x+y;
}

value_type fn_diff(value_type x, value_type y){
  return x-y;
}

value_type sum(Sorted_List *list){
  return reduce(list,fn_add,0,INSERTED_ORDER);
}

Sorted_List *square(Sorted_List *list){
  return map(list,fn_square);
}

value_type fn_square(value_type x){
  return x*x;
}

value_type fn_sq_diff(value_type x, value_type y){
  return fn_square(fn_diff(x,y));
}

value_type sum_of_sq_diff(Sorted_List *list_1, Sorted_List *list_2, int order){
  return map_2_reduce(list_1,list_2,fn_sq_diff,fn_add,order);
}

value_type *diff (Sorted_List *list_1, Sorted_List *list_2, int order){
  if (size(list_1)!=size(list_2)){
    return NULL;
  }

  return map_2_array(list_1,list_2,fn_diff,order);
}

value_type reduce (Sorted_List *list, value_type (*fn)(),value_type init, int order){
  Node *p;
  if (order==INSERTED_ORDER){
    for(p=list->head;p!=NULL;p=p->next){
      init=fn(init,p->value);
    }
  }else if(order==SORTED_ORDER){
    for(p=list->head_sort;p!=NULL;p=p->sort){
      init=fn(init,p->value);
    }
  }

  return init;
}

value_type map_reduce (Sorted_List *list, Sorted_List *(*fn_map)(), value_type (*fn_reduce)(), value_type init, int order){
  Node *p;
  for (p=list->head;p!=NULL;p=p->next){
    init=fn_reduce(fn_map(p->value),init);
  }
  return init;
}

value_type *map_2_array (Sorted_List *list_1, Sorted_List *list_2,value_type (*fn)(), int order){
  Node *p;
  Node *q;
  value_type *value_array=calloc(size(list_1),sizeof(value_type));
  int i=0;

  if (order==INSERTED_ORDER){ /*Traverses with inserted order*/
    p=list_1->head;
    q=list_2->head;
    while (p!=NULL && q!=NULL){
      value_array[i++]=fn(p->value,q->value);
      p=p->next;
      q=q->next;
    }
  }else if(order==SORTED_ORDER){ /*Traverses with sort order*/
    p=list_1->head_sort;
    q=list_2->head_sort;

    while (p!=NULL && q!=NULL){
      value_array[i++]=fn(p->value,q->value);
      p=p->sort;
      q=q->sort;
    }
  }
  return value_array;
}

value_type map_2_reduce (Sorted_List *list_1, Sorted_List *list_2,value_type (*fn_map)(),value_type (*fn_reduce)(), int order){
  Node *p;
  Node *q;
  int total=0;

  if (order==INSERTED_ORDER){ /*Traverses with inserted order*/
    p=list_1->head;
    q=list_2->head;
    while (p!=NULL && q!=NULL){
      total=fn_reduce(fn_map(p->value,q->value),total);
      p=p->next;
      q=q->next;
    }
  }else if(order==SORTED_ORDER){ /*Traverses with sort order*/
    p=list_1->head_sort;
    q=list_2->head_sort;

    while (p!=NULL && q!=NULL){
      total=fn_reduce(fn_map(p->value,q->value),total);
      p=p->sort;
      q=q->sort;
    }
  }
  return total;
}
