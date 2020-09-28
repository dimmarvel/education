#include <sys/dir.h>

Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;
	static Dirent d;

	while(read(dp->fd, (char*)&dirbuf, sizeof(dirbuf))
			== sizeof(dirbuf))
	{
		if(dirbuf.d_ino == 0)
			continue;

		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';
		return &d;
	}
	return NULL;
}
