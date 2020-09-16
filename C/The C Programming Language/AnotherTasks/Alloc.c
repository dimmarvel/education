#include<stdio.h>
#define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char* alloc(int n)
{
	if (allocbuff + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return 0;
	}
}
void free(char* ptr)
{
	if (ptr >= allocbuff && ptr < allocbuff + ALLOCSIZE)
	{
		allocp = ptr;
	}
}

//
//main()
//{
//	char *some = alloc(10);
//	printf("%s", some);
//	free(some);
//
//	system("pause");
//}