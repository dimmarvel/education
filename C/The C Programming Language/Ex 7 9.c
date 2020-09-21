#include <ctype.h>

int isupper(char c)
{
	if (c >= 'A' && c =< 'Z')
		return 1;
	else
		return 0;
}

#define isupper(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0