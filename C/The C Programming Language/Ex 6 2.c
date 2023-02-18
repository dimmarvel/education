#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode
{                        // the tree node
    char* word;          // points to text
    int match;           // sign matches
    struct tnode* left;  // left child
    struct tnode* right; // right child
};

struct tnode* addtree(struct tnode*, char*, int, int*);
void treeprint(struct tnode*);
int getword(char*, int);

/* word frequency count */
int main(int argc, char** argv)
{
    struct tnode* root;
    char word[MAXWORD];
    int num;
    int find = NO;

    if (argc <= 1 || argc > 2 || atoi(*(argv + 1)) > 0)
    {
        printf("Wrong parameters, use default - 6 -\n");
        num = 6;
        printf("num = %d\n", num);
    }
    else
        num = abs(atoi(*(argv + 1)));
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root, word, num, &find);
        find = NO;
    }
    treeprint(root);
    return 0;
}

struct tnode* talloc(void);
int compare(char*, struct tnode*, int, int*);
char* s_dup(char* s);

/* adtree: add a node with w, at or below p */
struct tnode* addtree(struct tnode* p, char* w, int num, int* find)
{
    int cond;

    if (p == NULL) // a new word has arrived
    {
        p = talloc(); // make a new node
        p->word = s_dup(w);
        p->match = *find;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(w, p, num, find)) < 0)
        p->left = addtree(p->left, w, num, find);
    else if (cond > 0)
        p->right = addtree(p->right, w, num, find);
    return p;
}

int compare(char* s, struct tnode* p, int num, int* find)
{
    int i;
    char* t = p->word;
    for (i = 0; *s == *t; i++, s++, t++)
        if (*s == '\0')
            return 0;
    if (i >= num)
    {
        *find = YES;
        p->match = YES;
    }
    return *s - *t;
}

/* treeprint */
void treeprint(struct tnode* p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        if (p->match)
            printf("%s\n", p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode* talloc(void) { return (struct tnode*)malloc(sizeof(struct tnode)); }

/* make a duplicate of s */
char* s_dup(char* s)
{
    char* p;

    p = (char*)malloc(strlen(s) + 1); // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
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

/* getword: get next word or character from input */
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

/* comment */
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