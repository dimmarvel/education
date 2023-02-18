#include <iostream>
#include <stdarg.h>
using namespace std;

void error(int severity...)
{
    // severity степень тяжести ошибки, дальше список сток
    // завершающийся нулем
    va_list ap;
    va_start(ap, severity);
    // начало параметров
    for (;;)
    {
        char* p = va_arg(ap, char*);
        if (p == 0)
            break;
        cerr << p << ' ';
    }
    va_end(ap);
    // очистка параметров
    cerr << '\n';
    if (severity)
        exit(severity);
}
