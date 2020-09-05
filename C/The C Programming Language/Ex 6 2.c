#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORDS 100

struct tnode * addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char *, int);
struct tnode* talloc(void);
char* mstrdup(char*);

struct tnode
{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};


main()
{
	struct tnode * root;
	char word[MAXWORDS];

	root = NULL;

	while (getword(word, MAXWORDS) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	treeprint(root);
	return 0;
}


struct tnode * addtree(struct tnode* node, char* word)
{
	int cond;

	if (node == NULL)
	{
		node = talloc();
		node->word = mstrdup(word);
		node->count = 1;
		node->right = node->left = NULL;
	}
	else if (cond = strcmp(node->word, word) == 0)
	{
		node->count++;
	}
	else if(cond < 0) // if word <
	{
		node->left = addtree(node->left,word);
	}
	else //if word >
	{
		node->right = addtree(node->right, word);
	}

	return node;
}

void treeprint(struct tnode* root)
{
	if (root != NULL)
	{
		treeprint(root->left);
		printf("%s -> %d\n", root->word, root->count);
		treeprint(root->right);
	}
}

struct tnode* talloc(void)
{
	return (struct tnode*) malloc(sizeof(struct tnode));
}

char* mstrdup(char* word)
{
	char *p;

	p = (char*)malloc(strlen(word) + 1);
	
	if (p != NULL)
	{
		strcpy(p, word);
	}

	return p;
}


//--------------------------------------------
#define BUFSIZE 100

char buf[BUFSIZE];          //buffer for ungetch;
int bufp = 0;               //next free position in buf

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
/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, d;
	int getch(void);
	void ungetch(int);
	int in_comment(void);
	char *w = word;

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

