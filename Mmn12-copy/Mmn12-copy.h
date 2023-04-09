#define INT_SIZE sizeof(int) /* In order to add an int to the array */
#define ENLARGE_SIZE(size) ++size /* In order to enlarge the array size */
#define INT_FOUND 1 /* When scanf returns 1 an int was found */
#define MEMORY_ERROR 1 /* Return value for memory reallocate or dealllocate error */
#define TRUE 1 /* Sign that a number is present in the array */
#define FALSE 0 /* Sign that a number is not present in the array */
#define INITIAL_ARRAY_SIZE 0 /* Initial array size */
#define NO_ERRORS 0 /* Return value for main function- program was completed successfully */

/* Dynamic array struct has 2 memebers:
1. size- number of elements in the array. an int.
2. array_pointer- a pointer to the first element in the array. an int pointer. */
typedef struct {
	int size;
	int* array_pointer;
} dynamic_array;

/* Get_set function gets input from the user until it reaches EOF, and creates 2 arrays:
1. Set- the purpose of the program, holds the set, where a number does not appear more than once.
2. Full array- holds the full array, where all the numbers the user entered appear.
The purpose of this array is for the input to be displayed nicely.
The function uses add_number_to_array function to add all of the numbers the user entered to the full array.
The function uses number_in_array function to check if number is present in the set,
if it is not, the function uses add_number_to_array function and adds the number to the set.
Finally, it calls print_full_array to print the full array to display the input as it was received,
and uses free function to deallocate the memory of the full array pointer.
Returns a dynamic_array. */
dynamic_array get_set();

/*  Add_number_to_array function gets a pointer to a dynamic_array and the number the user entered.
If the size of the dynamic_array is 0, it uses malloc to allocate memory to the array.
Else, it uses realloc to reallocate more memory to the array.
Finally, it adds the number to the array. */
void add_number_to_array(dynamic_array* my_array, int number);

/* Number_in_array function gets a dynamic_array and the number the user enterd.
It loops through the array and checks if the number already exists in the array.
It returns an int. If the number exist, 1, else, it returns 0.*/
int number_in_array(dynamic_array my_array, int number);

/* Print_set function gets a dynamic_array,
loops through the array and prints each number of the set until it reaches the size of the dynamic_array. */
void print_set(dynamic_array set);

/* Print_full_arrau function gets a dynamic_array,
loops through the array and prints each number of the full array until it reaches the size of the dynamic_array. */
void print_full_array(dynamic_array full_array);