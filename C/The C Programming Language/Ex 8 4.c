int _fseek(_FILE *fp, long offset, int origin)
{
	unsigned nc; //discharged characters
	long rc = 0; //return code

	if (fp->flag.f_read)
	{
		if (origin == 1)
			offset -= fp->cnt;
		rc = lseek(fp->fd, offset, origin);
		fp->cnt = 0; //buffer is empty
	}
	else if (fp->flag.f_write)
	{
		if ((nc = fp->ptr - fp->base) > 0)
			if (write(fp->fd, fp->base, nc) != nc)
				rc = -1;
		if (rc != -1) // no error
			rc = lseek(fp->fd, offset, origin);
	}
	return (rc == -1) ? -1 : 0;
}