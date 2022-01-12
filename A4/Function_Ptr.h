#ifndef _FUNCTION_PTR_
#define _FUNCTION_PTR_

#include "Sorted_List.h"

#define INSERTED_ORDER 0
#define SORTED_ORDER 1

Sorted_List *filter(Sorted_List *list, int (*)());

/*
Takes in two value_types and returns their sum
*/
value_type fn_add(value_type, value_type);

/*
Takes in two value_types and returns their difference
*/
value_type fn_diff(value_type, value_type);

value_type fn_sq_diff(value_type, value_type);

value_type *diff (Sorted_List *, Sorted_List *, int);

/*
Takes in a Sorted_List and returns the sum of all its values
*/
value_type sum(Sorted_List *);

value_type sum_of_sq_diff(Sorted_List *, Sorted_List *, int);

/*
Takes in a Sorted_List and creates a new one where
every value is the square of the original list's value
*/
Sorted_List *square(Sorted_List *);

/*
Takes in an value_type and returns its square
*/
value_type fn_square(value_type);

/*

*/
void print_array(value_type *, int);

/*

*/
Sorted_List *map (Sorted_List *, value_type (*)());

/*

*/
value_type reduce (Sorted_List *, value_type (*)(),value_type, int);

/*

*/
value_type map_reduce (Sorted_List *, Sorted_List *(*)(), value_type (*)(), value_type, int);

/*

*/
value_type *map_2_array (Sorted_List *, Sorted_List *,value_type (*)(), int);

/*

*/
value_type map_2_reduce (Sorted_List *, Sorted_List *,value_type(*)(),value_type (*)(), int);

#endif
