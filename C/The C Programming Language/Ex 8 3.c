
int _flushbuf(int x, _FILE *fp)
{
    unsigned nc; //amount discharged characters
    int bufsize; //size of the allocated buffer
   
    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF; //wrong pointer
    if(fp->flag.f_write == 0 || fp->flag.f_err == 1)
        return EOF;
    bufsize = (fp->flag.f_unbuf == 1) ? 1 : BUFSIZ;
    if(fp->base == NULL) //buffer is not yet
    {
        if((fp->base = (char *) malloc(bufsize)) == NULL)
        {
            fp->flag.f_err = 1;
            return EOF; //can not takes buffer
        }
    }
    else //buffer is already
    {
        nc = fp->ptr - fp->base;
        if(write(fp->fd, fp->base, nc) != nc)
        {
            fp->flag.f_err = 1;
            return EOF;//error, return EOF
        }
    }
    fp->ptr = fp->base; //beginning of the buffer
    *fp->ptr++=(char)x;
    fp->cnt = bufsize - 1;
    return x;
}

int _fclose(_FILE *fp)
{
    int rc; //return code
   
    if((rc = _fflush(fp)) != EOF)
    {
        free(fp->base); // release memory buffer
        fp->ptr = NULL;
        fp->cnt = 0;
        fp->base = NULL;
        fp->flag.f_unbuf = 0;
        fp->flag.f_buf = 1;
        fp->flag.f_eof = 0;
        fp->flag.f_err = 0;
        fp->flag.f_read = 0;
        fp->flag.f_write = 0; 
    }
    return rc;
}

int _fflush(_FILE *fp)
{
    int rc = 0;
   
    if(fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF; //wrong pointer
    if(fp->flag.f_write)
        rc = _flushbuf(0, fp);
    fp->ptr = fp->base;
    fp->cnt = (fp->flag.f_unbuf == 1) ? 1 : BUFSIZ;
    return rc;
}