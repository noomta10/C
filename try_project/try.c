#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define NUM 15 
/* point record description */
struct point
{
	int x, y, z;
};
/* writes and then reads NUM records
 from the file "points_file". */
int main()
{
	int i, j;
	FILE* f;
	int r1, r2;
	struct point pnt;
	/* create a file of NUM records */
	f = fopen("points_file", "w");
	if (!f)
		return 1;

	pnt.y = 0;
	pnt.z = 0;
	for (i = 1;i <= NUM; i++)
	{
		pnt.x = i;
		pnt.y = i;
		fwrite(&pnt, 12, 1, f);
	}
	fclose(f);
	/* read the NUM records */
	f = fopen("points_file", "r");
	if (!f)
		return 1;
	for (i = 1;i <= NUM; i++)
	{
		fread(&pnt, sizeof(struct point), 1, f);
		printf("%d\n", pnt.x);
	}
	fclose(f);
	printf("\n");
	/* use fseek to read the NUM records
	in reverse order */
	f = fopen("points_file", "r");
	if (!f)
		return 1;
	for (i = NUM - 1; i >= 0; i--)
	{
		r1= fseek(f, sizeof(struct point) * i, SEEK_SET);
		r2 = fread(&pnt, sizeof(struct point), 1, f);
		printf("%d %d %d\n", r1, r2, pnt.x);
	}
	fclose(f);
	printf("\n");
	return 0;
}