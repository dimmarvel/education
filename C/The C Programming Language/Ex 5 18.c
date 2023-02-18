#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define YES 1
#define NO 0

enum
{
    NAME,
    PARENS,
    BRACKETS
};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;           // type of last token
char token[MAXTOKEN];    // last token string
char name[MAXTOKEN];     // identifier name
char datatype[MAXTOKEN]; // data type = char, int, etc.
char out[1000];
int errtoken = NO;
int errbrack = NO;

/* convert declaration to words */
int main()
{

    while (gettoken() != EOF) // 1st token on line
    {
        strcpy(datatype, token); // is the datatype
        out[0] = '\0';
        dcl(); // parse rest of line
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';) // count stars
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    if (tokentype == '(') //(dcl)
    {
        dcl();
        if (tokentype != ')')
        {
            printf("error: missing )\n");
            errtoken = YES;
        }
    }
    else if (tokentype == NAME) // variable name
        strcpy(name, token);
    else
    {
        printf("error: expected name or (dcl)\n");
        errtoken = YES;
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int getch(void);
void ungetch(int c);

int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char* p = token;

    if (errtoken == YES)
    {
        errtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; *p != ']';)
        {
            *p = getch();
            if (*p != ']')
            {
                if (*p == '\n' || *p == ')' || *p == '(')
                {
                    printf("error: missing ]\n");
                    ungetch(*p);
                    *p = ']';
                }
                else
                    *p++;
            }
        }
        *++p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch;
int bufp = 0;      // next free position in bud

int getch(void) // get a (possibly pushed-back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characnters\n");
    else
        buf[bufp++] = c;
}