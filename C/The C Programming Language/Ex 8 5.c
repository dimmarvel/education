#include <stdio.h>
#include <string.h>
#include <sys/stat.h> //structure returned by stat
#include <sys/types.h> //typedefs
#include <sys/syscall.h>
#include <fcntl.h> //flags for read and write
#include <dirent.h>
#include <sys/dir.h> //local directory structure

int stat(char *, struct stat *);
void dirwalk(char *, void(*fcn) (char *));

void fsize(char *name)
{
	struct stat stbuf;

	stat(name, &stbuf) == -1)
	{
		fprintf(stderr, "fsize: can`t acces %s\n", name);
		return;
	}
	if (stbuf.st_mode & S_IFMT) == S_IFDIR)
	dirwalk(name, fsize);
	printf("%8ld %s\n%u %ld\n", stbuf.st_size, name, stbuf.st_uid, stbuf.st_mtime);
}