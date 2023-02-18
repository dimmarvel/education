#include "dirent.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void fsize(char*);

main(int argc, char* argv[])
{
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

int stat(char*, struct stat*);
void dirwalk(char*, void (*fcn)(char*));

void fsize(char* name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1)
    {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);

    printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024
void dirwalk(char* dir, void (*fcn)(char*))
{
    char name[MAX_PATH];
    Dirent* dp;
    DIR* dfd;

    if ((dfd = opendir(dir)) == NULL)
    {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while ((dp = readdir(dfd)) != NULL)
    {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, ".." == 0))
            continue; // skip urself and parents

        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s %s too long\n");
        else
        {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
