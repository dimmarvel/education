#include <stdio.h>

main()
{
    int counterSpace = 0;
    int counterTab = 0;
    int counterEnter = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            counterSpace++;
        if (c == '\t')
            counterTab++;
        if (c == '\n')
            counterEnter++;
    }
    printf("Space - %d\n", counterSpace);
    printf("Tab - %d\n", counterTab);
    printf("Enter - %d\n", counterEnter);
    system("pause");
}