#include "_FILE.h"
#include <fcntl.h>
#include "syscalls.h"

#define PERMS 0666

FILE *fopen(char* name,char* mode)
{
	int fd;
	FILE* fp;

	if(*mode != 'r' && *mode != 'a' && *mode != 'w')
		return NULL;

	for(fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if((fp->flag & (_READ | _WRITE)) == 0)
			break; // we find empty place for file

	if(fp >= _iob + OPEN_MAX) //noone place for file
		return NULL;

	if(*mode == 'w')
		fd = creat(name, PERMS);
	else if(*mode == 'a'){
		if((fd = open(name,O_WRONLY,0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd,0l,2);
	}else
	{
		fd = open(name, O_RDONLY, 0);
	}

	if(fd == -1)
		return NULL;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}
