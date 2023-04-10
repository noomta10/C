#define ENLARGE_SIZE sizeof(int) /* In order to add an int to the array */
#define NUMBER_EXISTS 1 /* Sign that the number is present in the array */
#define NUMBER_DOESNT_EXIST 0 /* Sign that the number is not present in the array */
#define NUMBER_OF_ELEMENTS_INDEX 0 /* First index in the array holds the number of the elements in the array */  
#define NO_ERRORS 0 /* Return value for main function- program was completed successfully */
#define MEMORY_ERROR 1 /* Return value for memory reallocate or dealllocate error */
#define INT_FOUND 1 /* When scanf returns 1 an int was found */
#define INITIAL_ARRAY_SIZE 1 /* Initial array size */
#define FIRST_INDEX 1 /* First index for number */


/* Get_set function gets input from the user until it reaches EOF, and creates 2 arrays:
1. Set- the purpose of the program, holds the set, where a number does not appear more than once.
2. Full array- holds the full array, where all the numbers the user entered appear.
The purpose of this array is for the input to be displayed nicely
The function uses add_number_to_array function to add all of the numbers the user entered to the full array.
The function uses number_in_array function to check if number is present in the array,
if it is not, the function uses add_number_to_array function and adds the number to the set.
Then, the function puts in the first element of each array the number pf elements in the array,
which is the next free index (index variable) of the array minus 1.
Finally, it calls print_input to print the full array to display the input as it was received.
Returns a pointer to the set array */
int* get_set(void);

/* Print_set function gets the pointer to the set and the number of elements in the set,
loops through the array, and prints each number of the set. */
void print_set(int* set_pointer, int number_of_elements);

/* Add_number_to_array function gets the pointer to the pointer (the set pointer or to the full array pointer),
the number the user entered, the pointer to the size of the array, and the the pointer to the index.
First it increases the size variable and reallocates memory to the new number, 
then, it adds the number to the next free position in the array, and finally, increases the index variable. */
void add_number_to_array(int** pointer_to_pointer, int number, int* size_pointer, int* index_pointer);


/* Number_in_array function gets the number the user enterd, the set pointer and number of elements in the set.
It loops through the array and checks if the number already exists in the array.
If the number exist, it returns 1, else, it returns 0.*/
int number_in_array(int number, int* set_pointer, int number_of_elements);

/* Print_input function gets the full array pointer and the number of elements in the array.
It loops through the array and prints all the numbers the user entered,
so the input will be displayed even when it comes from a file. */
void print_input(int* full_array_pointer, int number_of_elements);
