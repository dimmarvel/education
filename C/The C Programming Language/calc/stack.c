#include "calc.h"
#include <stdio.h>

#define MAXVAL 100 // maximum depth of val stack

int sp;
double val[MAXVAL]; // value stack
int sp = 0;         // next free stack position

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can`t push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}