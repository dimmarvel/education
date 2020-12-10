//ЧТО МОЖНО
struct point {int x, y;}; //определения типов
template<class T> //шаблоны типов
class V {/*....*/};
extern int strlen(const char*); //описание функций
inline char get(){char*p; return *p++;} //определения
extern int a; //описание данных
const float pi = 3.141593; //определение констант
enum boolean {tru, fals};//перечисления
class Matrix;// описания имен
#include<signal.h> //команды включения файлов
#define Case break;case //макроопределения
/*...*/ //комментарии

//ЧТО НЕЛЬЗЯ
char get() {char* p; return *p++;} //определение обычных функций
int a; // определение данных
const tb[i] = {/*...*/}; //определение составных констант
