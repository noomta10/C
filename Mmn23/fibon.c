/* Noam Tamir */

#include "fibon.h"

/* Free_memory function gets a pointer to a pointer to the first node (the address of the first node pointer).
It loops through the nodes in the sequence and uses free function to free the memory. Does not return anything. */
void free_memory(Node** first_node_pointer) {
    Node* current_node = *first_node_pointer;
    Node* next_node;
    
    do {
        next_node = current_node->previous;
        free(current_node);
        current_node = next_node;
    } while(current_node != *first_node_pointer);
}


/* Write_fibonnaci_file function gets a Node pointer to the first node, the maximum index in the sequence, and a character pointer to the file name.
It creates a file, prints an error if one was encountered, and prints a title.
Then it loops through the sequence and prints the sequence in a descending order.
Finally, it closes the file. Does not return anything. */
void write_fibonacci_file(Node* first_node, int n, char* file_name) {
    FILE* file_pointer = fopen(file_name, "w");
    Node* current_node = first_node;

    if (file_pointer == NULL) {
        printf("Error opening file\n");
        exit(FILE_ERROR);
    }

    fprintf(file_pointer, "First elements in fibonacci sequence when maximun index n = %d\n", n);
    fclose(file_pointer);
    file_pointer = fopen(file_name, "a");

    do {
        fprintf(file_pointer, "%lu ", (current_node->previous)->number);
        current_node = current_node->previous;
    } while (current_node != first_node);

    fclose(file_pointer);
}


/* Print_fibonnaci function gets a Node pointer to the first node and the the maximum index in the sequence.
It prints the sequence in a descending order. Does not return anything. */
void print_fibonacci(Node* first_node, int n) {
    struct Node* current_node = first_node;
    printf("First elements in fibonacci sequence when maximun index n = %d\n", n);
    
    do {
        printf("%lu ", (current_node->previous)->number);
        current_node = current_node->previous;
    } while (current_node != first_node);

    printf("\n");
} 


/* Create_node function gets an unsigned long long number, which will be the node data.
It creates a new node- allocates memory to it, and sets its number to the number it recieved.
Returns the new node it created. */
Node* create_node(unsigned long number) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(MEMORY_ERROR);
    }

    new_node->number = number;
    return new_node;
}


/* Create_fibonacci function gets n- maximum index in the sequence the user entered and creates the fibonnaci sequence.
* The function uses create_node function in order to create each node in the sequence.
First, it creates the first node with number 0, checks if n is zero, and if so,
it returns the first node which points to itself. Then, it creates the second node with the number 1.
After that, it loops as long as the index of the sequence is smaller than the n,
and creates a circular descending order fibonnaci sequence.
Finally, it returns a pointer to the first node. */
Node* create_fibonacci(int n) {
    Node* first_node = create_node(FIRST_ELEMENT);
    Node* second_node;
    Node* current_node;
    Node* previous_node;

    int sequence_index;

    if (n == MIN_VALUE) {
        first_node->previous = first_node;
        return(first_node);
    }

    second_node = create_node(SECOND_ELEMENT);
    second_node->previous = first_node;
    current_node = second_node;
    previous_node = first_node;

    for (sequence_index = INDEX_ONE; sequence_index < n ; sequence_index++) {
        Node* new_node = create_node(current_node->number + previous_node->number);
        new_node->previous = current_node;
        previous_node = current_node;
        current_node = new_node;
    }
    
    first_node->previous = current_node;
    return first_node;
}


/* Get_file_name function gets the number of arguments- int argc,
and a pointer array which points to each argument passed to the program in the command line- char* argv[].
The function checks that the number of arguments that were passed in the command line is valid,
if it is not, it print an error message and exit the program.
If no errors were encounterd, returns the file name which is a pointer to characters */
char* get_file_name(int argc, char* argv[]) {
    char* file_name;

    if (argc > VALID_ARGUMENTS_NUMBER) {
        fprintf(stderr, "Error: too many arguments\n");
        exit(ARGUMNENTS_ERROR);
    }

    if (argc < VALID_ARGUMENTS_NUMBER) {
        fprintf(stderr, "Error: too few arguments\n");
        exit(ARGUMNENTS_ERROR);
    }

    file_name = argv[FILE_NAME_INDEX];
    return file_name;
}


/* Get_n_input function gets the initial n- int n.
I assume that n is not greater than 47 because this is the max value long data type can contain (4294967295).
The function checks that the number is positive, if it is not, it prints an error message ands asks again for an input.
Returns a valid number of n (maximum index in fibonacci sequence)- int n */
int get_n_input(int n) {
    printf("Enter n (maximum index in the sequence): ");
    scanf("%d", &n);

    while (n < 0) {
        fprintf(stderr, "Error: number of elements need to be a positive number\n");
        printf("Enter n (maximum index in the sequence): ");
        scanf("%d", &n);
    }

    return n;
}

/* Main function gets and checks command line arguments and users input, 
creates and prints fibonnaci sequence, and frees the memory that was allocated with malloc 
Return NO_ERRORS when the run completed successfuly. */
int main(int argc, char* argv[]) {
    Node* first_node;
    int n = INITIAL_VALUE;
    /* Get and check command line arguments and users input */
    char* file_name = get_file_name(argc, argv);
    n = get_n_input(n);

    /* Create and print fibonnaci sequence */
    first_node = create_fibonacci(n);
    write_fibonacci_file(first_node, n, file_name);
    print_fibonacci(first_node, n);
    
    /* Free the memory that was allocated with malloc */
    free_memory(&first_node);
    
    return NO_ERRORS;
}