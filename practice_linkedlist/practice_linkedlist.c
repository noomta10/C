#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	int data;
} Node;


void add_node(Node** head, int number) {
	Node* current_node;
	Node* new_node = malloc(sizeof(Node*));
	new_node->data = number;
	new_node->next = NULL;

	/* First node in the list */
	if (*head == NULL) {
		*head = new_node;
		return;
	}

	current_node = *head;
	/* If new node has the smallest number */
	if (current_node->data > number) {
		new_node->next = current_node;
		*head = new_node;
		return;
	}

	/* Search the right place for new node */
	while (current_node->next != NULL && current_node->next->data < number) {
		current_node = current_node->next;
	}
	current_node->next = new_node;

}


print_list(Node* head) {
	Node* current_node = head;
	while (current_node != NULL) {
		printf("%d\n", current_node->data);
		current_node = current_node->next;
	}
}


int main() {
	int number;
	Node* head = NULL;
	printf("Enter numbers:\n");

	while (scanf("%d", &number) == 1) {
		add_node(&head, number);
	}

	print_list(head);


}
