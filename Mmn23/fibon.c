#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;


void print_fibonacci(Node* first_node, int number_of_elements) {
    struct Node* previous_node = NULL;
    struct Node* current_node = first_node;
    struct Node* next_node;
    printf("Descending order of first %d elements in fibonacci sequence :\n");

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


int main() {
    int number_of_elements;
    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);

    Node* first_node = create_fibonacci(number_of_elements);
    print_fibonacci(first_node, number_of_elements);
    return 0;
}