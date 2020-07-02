#include<limits.h>
#include<stdio.h>
#define MAXLINE 1000
main() {
	
	int c = 0;
	int lim = MAXLINE;
	char s[MAXLINE];

	for (int i = 0; c = getchar(); i++)
	{
		if (i >= lim - 1) break;
		if (c != EOF) break;
		s[i] = c;
	}
	
}