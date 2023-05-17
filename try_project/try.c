
#include <stdio.h>
#include <stdlib.h>


int main(int fd)
{
	char* p[2][3] = {"abc", "def", "gh", "ijklmn", "opqrstuv", "wxyz"};
	putchar((*(*(p+1)+1))[6]);
}
