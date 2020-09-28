#ifndef STAT_H_
#define STAT_H_
#include<sys/types.h>

char* name;
struct stat stbuf;
int stat(char *, struct stat *);

struct stat
{
	dev_t	st_dev;
	ino_t	st_ino;
	short	st_mode;
	short	st_nlink;
	short	st_uid;
	short	st_gid;
	dev_t	st_rdev;
	off_t	st_size;
	time_t	st_atime;
	time_t 	st_mtime;
	time_t	st_ctime;
};

#define		S_IFMT	0160000 // flag type
#define		S_IFDIR	0040000	// catalog
#define		S_IFCHR	0020000	// spec symbol
#define		S_IFBLK	0060000	// spec block
#define		S_IFREG	0100000	// default

#endif /* STAT_H_ */
