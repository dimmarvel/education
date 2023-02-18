#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define HASHSIZE 101

void error(int, char*);
char* s_dup(char*);
int getch(void);
void ungetch(int);
int getword(char*, int);
void getdef(void);
void undef(char*);
void ungets(char*);
struct nlist* lookup(char*);
struct nlist* minstall(char*, char*);
void skipspace(void);
unsigned hash(char*);

struct nlist
{
    struct nlist* next;
    char* name;
    char* defn;
};

static struct nlist* hashtab[HASHSIZE];

/* a simple version of the #define processor */
int main()
{
    char word[MAXWORD];
    struct nlist* np;

    while (getword(word, MAXWORD) != EOF)
        if (strcmp(word, "#") == 0) // beginning def processor
            getdef();
        else if (!isalpha(word[0]))
            printf("%s\n", word); // can't define
        else if ((np = lookup(word)) == NULL)
            printf("%s\n", word); // not define
        else
            ungets(np->defn); // return definition
    return 0;
}

void getdef(void)
{
    int i;
    char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

    skipspace();
    if (!isalpha(getword(dir, MAXWORD)))
        error(dir[0], "getdef: after # waiting directive");
    else if (strcmp(dir, "define") == 0)
    {
        skipspace();
        if (!isalpha(getword(name, MAXWORD)))
            error(name[0], "getdef: not letter, waiting name");
        else
        {
            skipspace();
            for (i = 0; i < MAXWORD; i++)
                if ((def[i] = getch()) == EOF || def[i] == '\n')
                    break;
            def[i] = '\0';
            if (i <= 0) // not definition
                error('\n', "getdef: incomplete definition");
            else // put definition to table
                minstall(name, def);
        }
    }
    else if (strcmp(dir, "undef") == 0)
    {
        skipspace();
        if (!isalpha(getword(name, MAXWORD)))
            error(name[0], "getdef: not letter in directine undef");
        else
            undef(name);
    }
    else
        error(dir[0], "getdef: aftewr # waiting directive");
}

void error(int c, char* s)
{
    printf("Error: %s\n", s);
    while (c != EOF && c != '\n')
        c = getch();
}

void skipspace(void)
{
    int c;

    while ((c = getch() == ' ' || c == '\t'))
        ;
    ungetch(c);
}

void ungets(char* s)
{
    int len;

    len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}
unsigned hash(char* s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}

struct nlist* lookup(char* s)
{
    struct nlist* np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name))
            return np;

    return NULL;
}

struct nlist* minstall(char* name, char* defn)
{
    struct nlist* np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist*)malloc(sizeof(*np));
        if (np == NULL || (np->name = s_dup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
    {
        free((void*)np->defn);
    }

    if ((np->defn = s_dup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}

void undef(char* name)
{
    unsigned hashI = hash(name);

    if (hashtab[hashI] != NULL)
    {
        free((void*)hashtab[hashI]->name);
        free((void*)hashtab[hashI]->defn);
        free((void*)hashtab[hashI]);
    }
}

char* s_dup(char* s)
{
    char* p;

    p = (char*)malloc(strlen(s) + 1); // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characnters\n");
    else
        buf[bufp++] = c;
}

int getword(char* word, int lim)
{
    int c, d;
    int getch(void);
    void ungetch(int);
    int in_comment(void);
    char* w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == ' ' || c == '#')
    {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
    }
    else if (c == '\'' || c == '"')
    {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c)
            {
                w++;
                break;
            }
            else if (*w == EOF)
                break;
    }
    else if (c == '/')
    {
        if (((d = getch()) == '*'))
            c = in_comment();
        else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

int in_comment(void)
{
    int c;

    while ((c = getch()) != EOF)
        if (c == '*')
        {
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }
    return c;
}