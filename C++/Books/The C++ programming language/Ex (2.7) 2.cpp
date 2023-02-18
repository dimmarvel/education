#include <iostream>
extern char ch;
char ch = '0';

extern int count;
int count = 1;

extern char* name;
char* name;

struct complex
{
    float re, im;
};
struct complex some = {10., 10.};
complex cvar = {10., 10.};

extern complex sqrt(complex);
complex sqrt(complex some) { return some; }

extern int error_number;
int error_number = 100;

typedef complex point;
point p = {10., 10.};

extern float real(complex*);
float real(complex* p) { return p->re; };

extern const double pi;
const double pi = 3.1415926535897932385;

struct user
{
    char* name;
    int age;
};
struct user;

template <class T>
extern void abs(T);
template <class T>
void abs(T a)
{
    return a < 0 ? -a : a;
}

extern enum beer;
enum beer
{
    Carlsberg,
    Tuborg,
    Thor
};
