#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define ARRAYFMT 10

void minscanf(char *, ...);

void minscanf(char *fmt, ...)
{
	va_list ap; 
	char *p, *sval;
	int *ival, i;
	unsigned *uval;
	double *dval;
	char arrayfmt[ARRAYFMT]; //array of characters

	i = 0;
	va_start(ap, fmt);//establishes for the first unnamed argument
	for (p = fmt; *p; p++)
	{

		if (*p != '%')
		{
			arrayfmt[i++] = *p;
			continue;
		}
		arrayfmt[i++] = '%';
		for (; *(p + 1) && !isalpha(*(p + 1)); i++)
			arrayfmt[i] = *++p;
		arrayfmt[i++] = *(p + 1);//letter format
		arrayfmt[i] = '\0';
		switch (*++p) //letter format
		{
		case 'd':
		case 'i':
			ival = va_arg(ap, int *);
			scanf(arrayfmt, ival);
			break;
		case 'f':
			dval = va_arg(ap, double *);
			scanf(arrayfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			scanf(arrayfmt, sval);
			break;
		case 'o':
		case 'x':
		case 'X':
		case 'u':
		case 'e':
			uval = va_arg(ap, unsigned *);
			scanf(arrayfmt, uval);
			break;
		}
		i = 0;
	}
	va_end(ap);//clear, after finish
}