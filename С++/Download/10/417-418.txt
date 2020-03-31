// ptracc.cpp
// доступ к переменной через указатель
#include <iostream>
using namespace std;

int main ( )
{
  int var1 = 11;        // две переменные
  int var2 = 22;
  int* ptr;             // указатель на целое

  ptr = &var1;          // помещаем в ptr адрес переменной var1
  cout << *ptr << endl; // показываем содержимое переменной через указатель

ptr = &var2;            // помещаем в ptr адрес переменной var2
  cout << *ptr << endl; // показываем содержимое переменной через указатель

  return 0;
}


