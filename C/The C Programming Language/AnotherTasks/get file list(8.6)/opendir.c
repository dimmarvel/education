#include "dirent.h"
#include <stdio.h>
#include <sys/stat.h>

int fstat(int fd, struct stat*);

DIR* opendir(char* dirname)
{
    int fd;
    struct stat stbuf;
    DIR* dp;

    if ((fd = open(dirname, O_RDONLY)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR ||
        (dp = (DIR*)malloc(sizeof(DIR))) == NULL)
        return NULL;
    dp->fd = fd;
    return dp;
}
