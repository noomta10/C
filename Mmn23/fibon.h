#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  /* Provides input and output functions */
#include <stdlib.h> /* Provides memory allocation and deallocation functions */
#define NO_ERRORS 0 /* Return value for main function- program was completed successfully */
#define MEMORY_ERROE -2 /* Return value for a memory error */

/* Node struct is a self-referential struct.
sontains 2 members:
1. unsigned long long number- the data, the number the node holds.
2. struct Node* previous- a pointer to the previous node in the circular list. */
typedef struct Node {
    unsigned long long number;
    struct Node* previous;
} Node;

/* Free_memory function gets a pointer to a pointer to the first node (the address of the first node pointer).
It loops through the nodes in the sequence and uses free function to free the memory. Does not return anything. */
void free_memory(Node** first_node_pointer);

/* Write_fibonnaci_file function gets a Node pointer to the first node, the number of elements in the sequence, and a character pointer to the file name.
It creates a file, prints an error if one was encountered, and prints a title.
Then it loops through the sequence and prints the sequence in a descending order.
Finally, it closes the file. Does not return anything. */
void write_fibonacci_file(Node* first_node, int number_of_elements, char* file_name);

/* Print_fibonnaci function gets a Node pointer to the first node and the number of elements in the sequence.
It prints the sequence in a descending order. Does not return anything. */
void print_fibonacci(Node* first_node, int number_of_elements);

/* Create_node function gets an unsigned long long number, which will be the node data.
It creates a new node- allocates memory to it, and sets its number to the number it recieved.
Returns the new node it created. */
Node* create_node(unsigned long long number);

/* Create_fibonacci function gets the number of elements the user entered and creates the fibonnaci sequence.
* The function uses create_node function in order to create each node in the sequence.
First, it creates the first node with number 0, checks if the number of elements is zero, and if so,
it returns the first node which points to itself. Then, it creates the second node with the number 1.
After that, it loops as long as the index of the sequence is smaller than the number of elements,
and creates a circular ascending order fibonnaci sequence. Then, it reverses the order of the sequence to a descending order.
Finally, it returns a pointer to the first node. */
Node* create_fibonacci(int number_of_elements);

/* Check_arguments function gets the number of arguments- int argc,
and a pointer array which points to each argument passed to the program in the command line- char* argv[].
The function checks that the number of arguments that were passed in the command line is valid,
if it is not, it print an error message and exit the program.
If no errors were encounterd, returns the file name which is a pointer to characters */
char* check_arguments(int argc, char* argv[]);

/* Check_elements_number gets the number of elements the user entered- int number_of_elements.
The function checks that the number is positive, if it is not, it prints an error message ands asks again for an input.
Returns a valid number of elements- int number_of_elements */
int check_elements_number(int number_of_elements);