#include <stdio.h>
#include <string.h>

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int leap;
    char* p;

    if (year < 1)
        return -1;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];
    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > *(p + month))
        return -1;
    while (month > 0)
    {
        day += *p++;
        month--;
    }
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
    int leap;
    char* p;
    char* tmp;

    if (year < 1 || yearday < 1)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];
    tmp = p;
    if (leap == 1 && yearday > 366)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    if (leap == 0 && yearday > 365)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    while (yearday > *p++)
    {
        yearday -= *p;
    }
    *pmonth = p - tmp;
    *pday = yearday;
}

main()
{
    int m = 7;
    int d = 19;
    int y = 2020;
    printf("%d\n", day_of_year(y, m, d));
    month_day(2020, 201, &m, &d);
    printf("%d %d\n", m, d);
    system("pause");
}