#include <stdio.h>

main()
{
    int day, year;
    char monthname[20];
    char line[100];
    while (getline(line, sizeof(line)) > 0)
    {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
        {
            printf("valid: %s", line);
        }
        else if (sscanf(line, "%d/%s/%d", &day, monthname, &year) == 3)
        {
            printf("valid: %s", line);
        }
        else
        {
            printf("error: %s", line);
        }
    }
}