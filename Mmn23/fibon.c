#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int number;
    struct Node* next;
} Node;


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
        fprintf(file_pointer, "%d ", current_node->number);
        current_node = current_node->next;
    } while (current_node != first_node);

    fclose(file_pointer);
}


void print_fibonacci(Node* first_node, int number_of_elements) {
    struct Node* previous_node = NULL;
    struct Node* current_node = first_node;
    struct Node* next_node;
    printf("Descending order of first %d elements in fibonacci sequence:\n", number_of_elements);

    /* Reverse to descending order */
    do {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    } while (current_node != first_node);

    /* Previous_node is the head of the list */
    Node* last_node = previous_node;

    /* Print the descending list */
    while (last_node != NULL) {
        printf("%d ", last_node->number);
        last_node = last_node->next;
    }
} 


Node* create_node(int number) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }

    new_node->number = number;
    return new_node;
}


Node* create_fibonacci(int number_of_elements) {
    Node* first_node = create_node(0);
    Node* second_node = create_node(1);
    first_node->next = second_node;

    if (number_of_elements == 0) {
        first_node->next = first_node;
        return(first_node);
    }

    Node* current_node = second_node;
    Node* previous_node = first_node;

    for (int elements = 2; elements < number_of_elements; elements++) {
        Node* new_node = create_node(current_node->number + previous_node->number);
        current_node->next = new_node;
        previous_node = current_node;
        current_node = new_node;
    }
    
    current_node->next = first_node;
    return first_node;
}

void check_arguments_number(argc) {
    if (argc > 2) {
        fprintf(stderr, "Error: too many arguments\n");
        exit(-1);
    }
    if (argc < 2) {
        fprintf(stderr, "Error: too few arguments\n");
        exit(-1);
    }
}


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


int main(int argc, char* argv[]) {
    int number_of_elements = NULL;
    
    check_arguments_number(argc);
    char* file_name = argv[1];

    number_of_elements = check_elements_number(number_of_elements);

    Node* first_node = create_fibonacci(number_of_elements);
    write_fibonacci_file(first_node, number_of_elements, file_name);
    print_fibonacci(first_node, number_of_elements);
    return 0;
}