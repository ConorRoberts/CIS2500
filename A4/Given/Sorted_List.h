/**
 *  @file Sorted_List.h
 *  @author Nathan Laundry
 *  @date Apr 2020
 *  @brief File Containing the function definitions of a linked list
 */
#ifndef _SORTED_LIST_API_
#define _SORTED_LIST_API_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Node Data Type
 * value_type is determined at compile time to be int or char
 * key_type is determined at compile time to be
 * Double if value_type is int
 * Int if value_type is char
 * Node * next is used for INSERTION ORDER
 * Node * sort is used for ascending sort order by key value
 */

/**
 * These set value_type and key_type to the proper types based on compiler flags
 * We use these compiler flags in the makefile
 */
#ifdef INT
    typedef int value_type;
    typedef double key_type;
#endif

#ifdef CHAR
    typedef char value_type[80];
    typedef int key_type;
#endif

typedef struct NODE {
    value_type value;
    key_type key;
    struct NODE * next;
    struct NODE * sort;
} Node;

/**
 * Sorted_List Data Type
 * Node * head used for insertion order
 * Node * head_sort used for ascending sort order by key value
 * Node * tail used for last node by insertion order
 * Node * tail_sort used for last node by ascending sort order by key value*/
typedef struct LIST {
    /*one head for insertion order, one for sorted order*/
    Node * head;
    Node * head_sort;
    
    /*Keeps track of the end of your list*/
    Node * tail;
    Node * tail_sort;
    
    int size;
} Sorted_List;

/** 
 * Define statements for FAILURE and SUCCESS
 * We can use FAIL in place of 0
 * SUCCESS in place of 1
 * For greater human readability
 */
#define FAIL 0
#define SUCCESS 1

/** 
 * Size
 * Returns: Number of nodes in the list  (NOT the State enum we created above)
 */
int size ( Sorted_List * list );

/** 
 * push
 * Returns SUCCESS or FAIL
 * FAIL condition is very rare, for things like Malloc returning NULL
 * Produce a new Node
 * Make that node the insert order head
 * Insert the node by ASCENDING sort order as well
 * Sort order is determined by key value
 */
int push ( Sorted_List * list, value_type value, key_type key );

/** 
 * append
 * Returns SUCCESS or FAIL
 * Produce a new Node
 * Make that node the insert order tail
 * Insert the node by ASCENDING sort order as well
 * Sort order is determined by key value
 */
int append ( Sorted_List * list, value_type value, key_type key );

/** 
 * remove_first
 * Removes the node from the head of the list
 * Store the value and key of that node in the value_type and key_type arguments given
 * Returns SUCCESS when successfully removed
 * Free the Node removed 
 * Update the sort order links as well
 */
int remove_first( Sorted_List* list, value_type * value, key_type * key );

/** 
 * remove_last
 * Removes the node from the tail of the list
 * All other instructions same as remove_first
 */
int remove_last( Sorted_List* list, value_type * value, key_type * key );

/**
 * remove_smallest_key
 * Removes the node from the head_sort of the list
 * Store the value and key of that node in the value_type and key_type arguments given
 * Returns SUCCESS when successfully removed
 * Free the Node removed 
 * Update the insertion order links as well
 */
int remove_smallest_key ( Sorted_List * list, value_type * value, key_type * key );

/** 
 * remove_largest_key
 * Removes the node from the tail_sort of the list
 * All other instructions same as remove_smallest_key
 */
int remove_largest_key( Sorted_List* list, value_type * value, key_type * key );

/** 
 * empty_list
 * destroys all nodes from the list
 * frees the memory of each node and its values if necessary
 */ 
void empty_list ( Sorted_List * list );

/** 
 * destroy_list
 * empty the list as described above
 * Free the list itself
 */
void destroy_list ( Sorted_List * list );

/** 
 * print_all
 * prints the key value pair of each node in insertion order
 * Better practice would be to return a string and print it elsewhere
 * Feel free to replace the return with a string if you're cool like that
 */
void print_all ( Sorted_List * list);

/** 
 * print_sort
 * prints the key value pair of each node in insertion order
 * Better practice would be to return a string and print it elsewhere
 * Feel free to replace the return with a string if you're cool like that
 */
void print_sort ( Sorted_List * list );

#endif
