#define _CRT_SECURE_NO_WARNINGS 

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
