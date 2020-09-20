#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define NAME 20

FILE *in;
int except = 0;
int number = 0;
long lineno = 0;

int getline(char *line, int max);
void fstdin(char *line, char *pattern);
void ffile(FILE *fp, char *pattern, char *line, char *file_name);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	char pattern[MAXLINE];
	char file[NAME];
	;
	int c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c)
			{
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				break;
			}
	if (argc < 1)
	{
		printf("Usage: find -x -n pattern file...\n");
		return 1;
	}
	else
		strcpy(pattern, *argv);
	if (argc == 1) // read from stdin
		fstdin(line, pattern); //search in the string
	else
			while (--argc != 0) //get file`s name
			{
				strcpy(file, *++argv);
				if ((in = fopen(file, "r")) == NULL)
				{
					perror(file);
					return 1;
				}
				else
				{
					ffile(in, pattern, line, file); //search in the file
					fclose(in);
				}
			}
	return 0;
}

void ffile(FILE *in, char *pattern, char *line, char *file_name)
{
	while (!feof(in))
	{
		fgets(line, MAXLINE - 1, in);
		lineno++;
		if ((strstr(line, pattern) != NULL) != except)
		{
			printf("%s\n", file_name);
			if (number)
				printf("%ld: ", lineno);
			printf("%s", line);
		}
	}
}

void fstdin(char *line, char *pattern)
{
	while (getline(line, MAXLINE) > 0)
	{
		lineno++;
		if ((strstr(line, pattern) != NULL) != except)
		{
			if (number)
				printf("%ld: ", lineno);
			printf("%s", line);
		}
	}
}

int getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL)
		return 0;
	else
		return strlen(line);
}