#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minpritf(char* fmt, ...);

int main()
{
	minpritf("%d", 100);
	return 0;
}


void minpritf(char* fmt, ...)
{
	va_list ap;
	char* p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);

	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*sval);
			break;
		}
	}

	va_end(ap);
}