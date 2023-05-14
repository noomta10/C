/* The library function calloc(n, size) using malloc */
#include <stdlib.h> 
#include <string.h> 

void* mycalloc(size_t nobj, size_t size) {
	void* result = NULL;

	/* use malloc to get the memory */
	result = malloc(nobj * size);

	/* clear the memory */
	if (NULL != result)
		memset(result, 0x00, nobj * size);

	/* return the result */
	return result;
}


/* sample: use of mycalloc */
#include <stdio.h> 
#define MSIZE 100

void main() {
	int* p = NULL, i = 0;

	p = mycalloc(MSIZE, sizeof * p);
	if (NULL == p)
		printf("mycalloc ERROR.\n");
	else {
		for (i = 0; i < MSIZE; i++)
			printf("%X ", p[i]);

		free(p);
	}
}