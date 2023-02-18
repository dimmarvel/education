#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum
{
    NAME,
    PARENS,
    BRACKETS
};
enum
{
    NO,
    YES
};

void dcl(void);      // parse a declarator
void dirdcl(void);   // parse a direct declarator
void errmesg(char*); // error message
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
    void paramdcl(void); // declarator analysis with parameters

    if (tokentype == '(') //(dcl)
    {
        dcl();
        if (tokentype != ')')
            errmesg("error: missing )\n");
    }
    else if (tokentype == NAME) // variable name
    {
        if (name[0] == '\0')
            strcpy(name, token);
    }
    else
        errtoken = YES;
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
        if (type == PARENS)
            strcat(out, " function returning");
        else if (type == '(')
        {
            strcat(out, " function taking");
            paramdcl();
            strcat(out, " and returning");
        }
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

/* errmesg: error message */
void errmesg(char* msg)
{
    printf("%s", msg);
    errtoken = YES;
}

#include <stdlib.h>

void declspec(void); // specification declaration
int typespec(void);  // type specifier
int typedesc(void);  // descriptor type

/* paramdcl: declarator analysis with parameters */
void paramdcl(void)
{
    do
    {
        declspec(); // specification declaration
    } while (tokentype == ',');
    if (tokentype != ')')
        errmesg("missing ) in declarator of parameters\n");
}

/* specification declaration */
void declspec(void)
{
    char temp[MAXTOKEN];

    temp[0] = '\0';
    gettoken();
    do
    {
        if (tokentype != NAME)
        {
            errtoken = YES;
            dcl();
        }
        else if (typespec() == YES) // type specifier
        {
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        }
        else if (typedesc() == YES) // descriptor type
        {
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        }
        else
            errmesg("error: unknown type in the parameter list\n");
    } while (tokentype != ',' && tokentype != ')');
    strcat(out, temp);
    if (tokentype == ',')
        strcat(out, ",");
}

/* type specifier */
int typespec(void)
{
    static char* types[] = {"char", "int", "void"};
    char* ptypes = token;
    int result, i;

    result = NO;
    for (i = 0; i < 3; i++)
        if (strcmp(ptypes, *(types + i)) == 0)
            return result = YES;
        else
            result = NO;
    return result;
}

/*  descriptor type */
int typedesc(void)
{
    static char* typed[] = {"const", "volatile"};
    char* ptd = token;
    int result, i;

    result = NO;
    for (i = 0; i < 2; i++)
        if (strcmp(ptd, *(typed + i)))
            return result = YES;
        else
            result = NO;
    return result;
}

int getch(void);   // get a (possibly pushed-back) character
void ungetch(int); // push character back on input

int gettoken(void)
{
    int c;
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
                    p++;
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
int bufp = 0;      // next free position in buf

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