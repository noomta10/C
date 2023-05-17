#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

void print_fibonacci(Node* first_node, int number_of_elements) {
    Node* current_node = first_node;

    for (int i = 0; i < number_of_elements; i++) {
        printf("%d, ", current_node->number);
        current_node = current_node->next;
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

    for (int elements = 0; elements < number_of_elements; elements++) {
        Node* new_node = create_node(current_node->number + previous_node->number);
        current_node->next = new_node;
        previous_node = current_node;
        current_node = new_node;
    }
    
    current_node->next = first_node;
    return current_node;
}




int main() {
    int number_of_elements = 10;
    Node* last_node = create_fibonacci(number_of_elements);
    print_fibonacci(last_node, );
    return 0;
}