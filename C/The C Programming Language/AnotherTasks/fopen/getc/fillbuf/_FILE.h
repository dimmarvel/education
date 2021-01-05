#ifndef FILE_H_
#define FILE_H_

#define NULL 0
#define EOF (-1)
#define BUFSIZE 1024
#define OPEN_MAX 20



typedef struct _iobuf
{
	int cnt;     //how symbols is left
	char* ptr;   //next symbol pos
	char* base;  //location of the buff
	int flag;    //flag access to file
	int fd;		 //descritpor of file
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags
{
	_READ 	= 01,
	_WRITE 	= 02,
	_UNBUF 	= 04,
	_EOF 	= 010,
	_ERR 	= 020,
};

FILE _iob[OPEN_MAX] = {
		{ 0, (char*) 0,(char*) 0, _READ, 0},
		{ 0, (char*) 0,(char*) 0, _WRITE, 0},
		{ 0, (char*) 0,(char*) 0, _WRITE | _UNBUF, 0}
};

extern int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0) \
				? (unsigned char) *(p)->ptr++ : _fillbuf(p))

#define putc(x,p) (--(p)->cnt >= 0) \
				? *(p)->ptr++ = (x) : _fillbuf((x),p))

#define getchar() getc(stdin)
#define putchar() putc((x), stdout)

#endif /* FILE_H_ */
