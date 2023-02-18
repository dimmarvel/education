#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int c, ntab, nspace, symv;

    if (argc != 2)
    {
        printf("ERROR -> wrong parameters\n");
        return 1;
    }

    symv = 1;
    ntab = 0;
    nspace = 0;

    while ((c = getchar()) != EOF)
    {
        symv++;
        if (c == ' ')
        {
            if (symv % atoi(*(argv + 1)) == 0)
            {
                ntab++;
                nspace = 0;
            }
            else
                nspace++;
        }
        else
        {
            while (ntab > 0)
            {
                putchar('\t');
                ntab--;
            }
            if (c == '\t')
            {
                nspace = 0;
                putchar('\t');
                symv = symv + (atoi(*(argv + 1)) - (symv % atoi(*(argv + 1))));
            }
            else
            {
                while (nspace > 0)
                {
                    putchar(' ');
                    nspace--;
                }
                putchar(c);
                if (c == '\n')
                {
                    symv = 0;
                    ntab = 0;
                    nspace = 0;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int c, i, symvol, ntab;

    if (argc != 2 || atoi(argv[1]) <= 0)
    {
        printf("ERROR -> wrong parametrs\n");
        return 1;
    }
    symvol = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            ntab = atoi(argv[1]) - (symvol - 1);
            for (i = 0; i < ntab; i++)
                putchar(' ');
            symvol = 0;
        }
        else if (c == '\n')
        {
            symvol = 0;
            printf("\n");
        }
        else
            putchar(c);
        symvol++;
        if (symvol == atoi(argv[1]))
            symvol = 0;
    }
    return 0;
}