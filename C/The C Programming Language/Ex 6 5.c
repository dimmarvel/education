#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char *s_dup(char *s);

struct nlist{
	struct nlist * next;
	char * name;
	char * defn;

};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char * s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

struct nlist * lookup(char* s)
{
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name))
			return np;

	return NULL;
}

struct nlist* minstall(char* name, char * defn)
{
	struct nlist * np;
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

main()
{
	struct nlist* nl = minstall("IN", "1");

	printf("%s -> %s", hashtab[hash("IN")]->name, hashtab[hash("IN")]->defn);
	undef("IN");
	return 0;

}

/* make a duplicate of s */
char *s_dup(char *s)
{
	char *p;

	p = (char *)malloc(strlen(s) + 1); // +1 for '\0'
	if (p != NULL)
		strcpy(p, s);
	return p;
}