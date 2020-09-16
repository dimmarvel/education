#include<stdio.h>

main(int argc, char *argv[])
{

	for (int i = 0; i < argc; i++)
	{
		printf("%s%s", argv[i], (i < argc) ? "" : "");
	}

	printf("\n");
	return 0;
}