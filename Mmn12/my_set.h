

#define ENLARGE_SIZE sizeof(int) /* In order to add an int to the array */
#define NUMBER_EXISTS 1 /* Sign that the number is present in the array */
#define NUMBER_DOESNT_EXIST 0 /* Sign that the number is not present in the array */
#define NUMBER_OF_ELEMENTS_INDEX 0 /* First index in the array holds the number of the elements in the array */  
#define NO_ERRORS 0 /* Return value for main function- the run was completed successfully */
#define MEMORY_ERROR 1 /* Return value for memory reallocate or dealllocate error */
#define INT_FOUND 1 /* When scanf returns 1 an int was found */
#define INITIAL_ARRAY_SIZE 1 // Initial array size */
#define FIRST_INDEX 1 /* First index for number */

int* get_set(void);
void print_set(int* set_pointer, int number_of_elements);
void add_number_to_array(int** pointer_to_pointer, int number, int* size, int* index_pointer);
int number_in_array(int number, int* array_pointer, int number_of_elements);
void print_input(int* full_array_pointer, int number_of_elements);

