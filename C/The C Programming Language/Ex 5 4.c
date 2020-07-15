#include <stdio.h>

short int strend(char*, char*);

main()
{
	char str1[13] = "some strw";
	char str2[5] = "strw";
	printf("%d\n", strend(str1, str2));
	system("pause");
}

short int strend(char* s, char* t)
{
	char *ptr;
	while (*s++ != '\0' && *t != '\0')
	{
		int count = 0;
		while (*t == *s && *t != '\0' && *s != '\0')
		{
			*t++;
			*s++;
			count++;
		}

		if (*t == '\0' && *s == '\0')
		{
			return 1; //if t in end s
		}
		
		while (count)
		{
			t--;
			count--;
		}
	}
	return 0; //if not t in end s
}