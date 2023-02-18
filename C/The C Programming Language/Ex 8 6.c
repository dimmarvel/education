#include <stdio.h>
#include <stdlib.h>

void _calloc(unsigned n, unsigned size)
{
    unsigned i, nsize;
    char *p, *q;

    nsize = n * size;
    if ((p = q = malloc(nsize)) != NULL)
        for (i = 0; i < nsize; i++)
            *q++ = 0;
    return p;
}