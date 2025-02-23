TP
Linked Lists
Recap of some course concepts:
A linked list is a data structure that allows storing a sequence of values.
Each cell in the list contains a value and provides access to the next cell.

Example:

Code:

struct cell(
    int value;
    struct cell * next;
);
**Exercise 1:**
a. Write a C function to create a node of a linked list.

The structure used for the list cells should consist of:

An integer;

A pointer to the list structure.

b. Write a function to add a node at the beginning of the linked list.

c. Write a function to add a node at the end of the linked list.

d. Write a function to display all elements of a linked list.

e. Write a function to delete the first element of the list.

f. Write a function to delete the last element of the list.

g. Write a function to delete an element with a specific value.
