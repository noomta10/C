#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Node struct is a self-referential struct.
sontains 2 members:
1. unsigned long long number- the data, the number the node holds.
2. struct Node* next- a pointer to the next node in the circular list. */
typedef struct Node {
    unsigned long long number;
    struct Node* next;
} Node;