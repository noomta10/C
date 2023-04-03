#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 1; // initial size of the array
    int count = 0; // number of elements entered by the user
    int* arr = malloc(size * sizeof(int)); // allocate memory for the array

    if (arr == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    printf("Enter numbers (enter 0 to stop):\n");

    while (1) {
        int num;
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (count == size) {
            // if the array is full, double its size using realloc()
            size *= 2;
            arr = realloc(arr, size * sizeof(int));

            if (arr == NULL) {
                printf("Error: memory reallocation failed\n");
                exit(1);
            }
        }

        arr[count++] = num; // add the number to the array
    }

    printf("The array contains %d elements:\n", count);

    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr); // free the memory used by the array
    return 0;
}