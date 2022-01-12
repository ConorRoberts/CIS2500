#ifndef _SORTED_LIST_
#define _SORTED_LIST_

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Fractions.h"

#define COMMAND_SIZE 25

#define SUCCESS 1
#define FAIL 0

#ifdef INT
  typedef int value_type;
  typedef double key_type;
#endif

#ifdef FRACT
  typedef Fraction value_type;
  typedef double key_type;
#endif

#ifdef CHAR
  typedef char value_type[80];
  typedef int key_type;
#endif

typedef struct NODE{
  value_type value;
  key_type key;
  struct NODE *next;
  struct NODE *sort;
  struct NODE *prev;
  struct NODE *prev_sorted;
}Node;

typedef struct{
  Node *head;
  Node *head_sort;
  Node *tail;
  Node *tail_sort;
  int size;
}Sorted_List;

void command_q1a(char [COMMAND_SIZE], Sorted_List *, value_type , key_type );

void print_all(Sorted_List *);

void print_sort(Sorted_List *);

Sorted_List *new_list();

void sort_list(Sorted_List *);

void remove_node(Sorted_List *, Node *);

int size (Sorted_List *);

int remove_largest_key (Sorted_List *, value_type *, key_type *);

void empty_list (Sorted_List *);

int push (Sorted_List *, value_type, key_type);

int append (Sorted_List *, value_type, key_type);

void destroy_list (Sorted_List *);

int remove_first (Sorted_List *, value_type *, key_type *);

int remove_last (Sorted_List *, value_type *, key_type *);

int remove_smallest_key (Sorted_List *, value_type *, key_type *);

#endif
