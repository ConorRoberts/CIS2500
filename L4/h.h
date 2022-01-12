#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct NODE{
 int value;
 double key1;
 double key2;
 struct NODE *next;
 struct NODE *sort1;
 struct NODE *sort2;
}Node;

/*Creates a random double*/
double rand_double(double, double);

/*Creates a linked list of Nodes with random values*/
Node *createList(int);

/*Prints linked list of Nodes using next pointer*/
void printList(Node *);

/*Frees linked list*/
void freeList(Node *);

/*Returns head of a linked list of Nodes sorted by key1*/
Node *sort1(Node *head);

/*Prints linked list of Nodes using sort1 pointer*/
void sort1Print(Node *head);

/*Returns head of a linked list of Nodes sorted by key2*/
Node *sort2(Node *head);

/*Prints linked list of Nodes using sort2 pointer*/
void sort2Print(Node *head);
