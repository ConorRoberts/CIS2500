# A4 Q1a Shell

## What is this?

This set of files acts as a starting point and a set of suggestions for how to 
structure your Assignment 4 q1 solutions.

As of this release q1b is not included although I would suggest adding the
map, reduce, map_reduce, and map_2_array to the Sorted_List files.

## Compilation and make commands and running

* To compile simply type make and the makefile will produce executables for both
     char and int value_types.
* We use conditional compilation as defined in the assignment description to 
     select Char or Int related functions.
* The compiler flags -DINT and -DCHAR allow us to do this.
* make clean removes all object files and executables
* ./a4q1a_int.out and ./a4q1a_char.out run the tests
* Further details are provided inside the makefile itself.

## Files

* Sorted_List.c and .h: 
    * These files house all the functions related to the linked list data type
      itself
* Commands.c and .h:
    * These files contain all the verbose commands related to reading the
      input files, and connecting them to the appropriate Sort_List functions 
      to perform the command 
* a4q1a_int.c and a4q1a_char.c :
    * These are files where you can write code that tests your linked list and
      input command processing implementation

