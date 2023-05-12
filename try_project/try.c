<<<<<<< HEAD
﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define NUM 15 

/* point record description */
struct point{
	int x, y, z;
};

/* writes and then reads NUM records from the file "points_file". */
int main() {
	int i, j;
	FILE* f;
	struct point pnt;

	/* create a file of NUM records */
	f = fopen("points_file", "w");
	if (!f)
		return 1;
	for (i = 1;i <= NUM; i++) {
		pnt.x = i;
		fwrite(&pnt, sizeof(struct point), 1, f);
	}
	fclose(f);

	/* read the NUM records */
	f = fopen("points_file", "r");
	if (!f)
		return 1;
	for (i = 1;i <= NUM; i++) {
		fread(&pnt, sizeof(struct point), 1, f);
		printf("%d\n", pnt.x);
	}
	fclose(f);
	printf("\n");

	/* use fseek to read the NUM records in reverse order */
	f = fopen("points_file", "r");
	if (!f)
		return 1;
	for (i = NUM - 1; i >= 0; i--) {
		fseek(f, sizeof(struct point) * i, SEEK_SET);
		fread(&pnt, sizeof(struct point), 1, f);
		printf("%d\n", pnt.x);
	}
	fclose(f);
	printf("\n");
	return 0;
}
=======
﻿#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>


main()
{
    FILE* fp;
fp = fopen("Hello there.bye", "r");
/* There can't be a file with such a name */
if (fp == NULL)
{
    perror("myprog");
    exit(7);
}
}
>>>>>>> f56d696bdd001869b4503ebbc4d87266f8e4e8cd
