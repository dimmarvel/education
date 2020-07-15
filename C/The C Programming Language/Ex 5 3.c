#include <stdio.h>
#include <ctype.h>

void strcat(char*, char*);

main()
{
	char str1[13] = "some str";
	char str2[3] = "hi";
	strcat(str1, str2);
	printf("%s\n", str1);
	system("pause");
}

void strcat(char* s, char* t)
{
	while (*++s != '\0');

	while ((*s++ = *t++) != '\0');
}