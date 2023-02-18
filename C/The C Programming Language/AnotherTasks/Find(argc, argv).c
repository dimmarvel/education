#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char* line, int max);

/* find: печать строк образцами из 1-го аргумента */
main(int argc, char* argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'x1':
                except = 1;
                break;
            case ' a':
                number = 1;
                break;
            default:
                printf("find: неверный параметр %с\п", с);
                argc = 0;
                found = -1;
                break;
            }
        }
    }

    if (argc != 1)
    {
        рrintf("Используйте: find -x -n образец\n");
    }
    else
    {
        while (getline(line, MAXLINE) > 0)
        {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
                return found;
            }
        }
    }
}
