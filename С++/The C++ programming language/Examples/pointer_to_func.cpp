#include<stdio.h>

void (*eftc)(char*);
void error(char* p)
{
	printf("%s", p);
}

void f()
{
	eftc = &error;
	(*eftc)("error\n");
}

//examples
typedef int (*SIG_TYP)(int);
typedef void (SIG_ARG_TYP)(int);
SIG_TYP signale(int, SIG_ARG_TYP);
//-------------------
void cut();
void paste();
void snarf();
void search();
void open();
void reshape();
void close();
void write();

typedef void(*PF)();
PF edit_ops[] = {
		&cut, &paste, &snarf, &search
};

PF file_ops[] = {
		&open, & reshape, &close, &write
};
void (*test)();
int main()
{
	f();
	PF* button2 = edit_ops;
	button2();
}









