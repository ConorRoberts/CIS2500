/*ALL documentation in associated .h file*/

#include "Sorted_List.h"

int size ( Sorted_List * list ) {
    return 0;
}

int push ( Sorted_List * list, value_type value, key_type key ) {
    return SUCCESS;
}

int append ( Sorted_List * list, value_type value, key_type key ) {
    return SUCCESS;
}

int remove_first( Sorted_List* list, value_type * value, key_type * key ) {
    return SUCCESS;
}

int remove_last( Sorted_List* list, value_type * value, key_type * key ) {
    return SUCCESS;
}

int remove_smallest_key ( Sorted_List * list, value_type * value, key_type * key ) {
    return SUCCESS;
}

int remove_largest_key( Sorted_List* list, value_type * value, key_type * key ) {
    return SUCCESS;
}

void empty_list ( Sorted_List * list ) {
    return;
}

void destroy_list ( Sorted_List * list ) {
    return;
}

/**
 * Print statements will be different based on the datatype
 * #ifdef lets us conditionally compile code based on which type we are using 
 */

/*Put Code for printing Integer data here*/
#ifdef INT
void print_all ( Sorted_List * list) {
    return;
}

void print_sort ( Sorted_List * list ) {
    return;
}

void print_key_value_pair(value_type value, key_type key) {
    return;
}
#endif

/*Put Code for printing Char data here*/
#ifdef CHAR
void print_all ( Sorted_List * list) {
    return;
}

void print_sort ( Sorted_List * list ) {
    return;
}

void print_key_value_pair(value_type value, key_type key) {
    return;
}
#endif
