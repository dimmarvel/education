#include <stdio.h>
#include <string.h>

static char daytab[2][13] = 
{
	{0,31,28,31,30,31,30,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,30,31,30,31}
};

int day_of_year(int year, int month, int day)
{

	if (year > 100000 || year < 1 || month > 12 || month < 1 || day > 365 || day < 1)
	{
		printf("data error\n");
		return -1;
	}

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; i < month; i++)
	{
		day += daytab[leap][i];
	}

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (year > 100000 || year < 1 || yearday > 365 || yearday < 1)
	{
		printf("data error\n");
		return;
	}

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; yearday > daytab[leap][i] ; i++)
	{
		yearday -= daytab[leap][i];
	}

	*pmonth = i;
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