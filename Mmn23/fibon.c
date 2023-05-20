#include "fibon.h"

/* Free_memory function gets a pointer to a pointer to the first node (the address of the first node pointer).
It loops through the nodes in the sequence and uses free function to free the memory. Does not return anything. */
void free_memory(Node** first_node_pointer) {
    Node* current_node = *first_node_pointer;
    Node* next_node;
    
    do {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    } while(current_node != *first_node_pointer);
}


/* Write_fibonnaci_file function gets a Node pointer to the first node, the number of elements in the sequence, and a character pointer to the file name.
It creates a file, prints an error if one was encountered, and prints a title.
Then it loops through the sequence and prints the sequence in a descending order. 
Finally, it closes the file. Does not return anything. */
void write_fibonacci_file(Node* first_node, int number_of_elements, char* file_name) {
    FILE* file_pointer = fopen(file_name, "w");
    Node* current_node = first_node;

    if (file_pointer == NULL) {
        printf("Error opening file\n");
        exit(-2);
    }

    fprintf(file_pointer, "First n elements in fibonacci sequence when n=%d\n", number_of_elements, number_of_elements);
    fclose(file_pointer);
    file_pointer = fopen(file_name, "a");

    do {
        fprintf(file_pointer, "%d ", (current_node->next)->number);
        current_node = current_node->next;
    } while (current_node != first_node);

    fclose(file_pointer);
}


/* Print_fibonnaci function gets a Node pointer to the first node and the number of elements in the sequence.
It prints the sequence in a descending order. Does not return anything. */
void print_fibonacci(Node* first_node, int number_of_elements) {
    struct Node* current_node = first_node;
    printf("Descending order of first %d elements in fibonacci sequence:\n", number_of_elements);
    
    /* Print the sequence in descending order */
    do {
        printf("%d ", (current_node->next)->number);
        current_node = current_node->next;
    } while (current_node != first_node);
} 


/* Create_node function gets an unsigned long long number, which will be the node data.
It creates a new node- allocates memory to it, and sets its number to the number it recieved.
Returns the new node it created. */
Node* create_node(unsigned long long number) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(-1);
    }

    new_node->number = number;
    return new_node;
}


/* Create_fibonacci function gets the number of elements the user entered and creates the fibonnaci sequence.
* The function uses create_node function in order to create each node in the sequence.
First, it creates the first node with number 0, checks if the number of elements is zero, and if so,
it returns the first node which points to itself. Then, it creates the second node with the number 1.
After that, it loops as long as the index of the sequence is smaller than the number of elements,
and creates a circular ascending order fibonnaci sequence. Then, it reverses the order of the sequence to a descending order.
Finally, it returns a pointer to the first node.
*/
Node* create_fibonacci(int number_of_elements) {
    Node* first_node = create_node(0);
    Node* second_node;
    Node* next_node;

    if (number_of_elements == 0) {
        first_node->next = first_node;
        return(first_node);
    }

    second_node = create_node(1);
    first_node->next = second_node;

    Node* current_node = second_node;
    Node* previous_node = first_node;

    for (int index = 1; index < number_of_elements ; index++) {
        Node* new_node = create_node(current_node->number + previous_node->number);
        current_node->next = new_node;
        previous_node = current_node;
        current_node = new_node;
    }
    
    current_node->next = first_node;


    /* Last node */
    previous_node = current_node;
    /* First node */
    current_node = first_node;

    /* Reverse */
    do {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    } while (current_node != first_node);

    return first_node;
}


/* Check_arguments function gets the number of arguments- int argc,
and a pointer array which points to each argument passed to the program in the command line- char* argv[].
The function checks that the number of arguments that were passed in the command line is valid,
if it is not, it print an error message and exit the program.
If no errors were encounterd, returns the file name which is a pointer to characters */
char* check_arguments(int argc, char* argv[]) {
    char* file_name;
    if (argc > 2) {
        fprintf(stderr, "Error: too many arguments\n");
        exit(-1);
    }
    if (argc < 2) {
        fprintf(stderr, "Error: too few arguments\n");
        exit(-1);
    }

    file_name = argv[1];
    return file_name;
}


/* Check_elements_number gets the number of elements the user entered- int number_of_elements.
The function checks that the number is positive, if it is not, it prints an error message ands asks again for an input.
Returns a valid number of elements- int number_of_elements */
int check_elements_number(int number_of_elements) {
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    while (number_of_elements < 0) {
        fprintf(stderr, "Error: number of elements need to be a positive number\n");
        printf("Enter number of elements: ");
        scanf("%d", &number_of_elements);
    }

    return number_of_elements;
}

/* Main function gets and checks command line arguments and users input, 
creates and prints fibonnaci sequence, and frees the memory that was allocated with malloc 
Return 0 when run completed successfuly. */
int main(int argc, char* argv[]) {
    /* Get and check command line arguments and users input */
    int number_of_elements = NULL;
    char* file_name = check_arguments(argc, argv);
    number_of_elements = check_elements_number(number_of_elements);

    /* Create and print fibonnaci sequence */
    Node* first_node = create_fibonacci(number_of_elements);
    write_fibonacci_file(first_node, number_of_elements, file_name);
    print_fibonacci(first_node, number_of_elements);
    
    /* Free the memory that was allocated with malloc */
    free_memory(&first_node);
    
    return 0;
}