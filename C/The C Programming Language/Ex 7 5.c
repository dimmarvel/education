#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
                push(pop() / op2);
            else
                printf("error: zero devisior\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero devisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100 // maximum depth of val stack

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
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getop(char s[])
{
    int i, c, rc;
    static char lastc[] = " ";

    c = lastc[0];
    lastc[0] = ' ';
    while ((s[0] = c) == ' ' || c == '\t')
        if (scanf("%c", &c) == EOF)
            c = EOF;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-')
    {
        scanf("%c", &c);
        rc = c;
        if (isdigit(c) || c == '.')
            s[++i] = c;
        else
        {
            if (rc != EOF)
                lastc[0] = c;
            return '-';
        }
    }
    if (isdigit(c)) // collect integer part
        do
        {
            scanf("%c", &c);
            rc = c;
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    if (c == '.')
        do
        {
            scanf("%c", &c);
            rc = c;
            if (!isdigit(s[++i] = c))
                break;
        } while (rc != EOF);
    s[i] = '\0';
    if (rc != EOF)
        lastc[0] = c;
    return NUMBER;
}