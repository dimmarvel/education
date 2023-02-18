#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        if (c == ' ')
        {
            while ((c = getchar()) == ' ')
                ;
            putchar(c);
        }
    }
    system("pause");
}