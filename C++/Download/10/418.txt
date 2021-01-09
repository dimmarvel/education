// ptrto.cpp
// еще один пример доступа через указатель
#include <iostream>
using namespace std;

int main ( )
{
  int var1, var2;       // две переменные
  int* ptr;             // указатель на целое

  ptr = &var1;          // пусть ptr указывает на var1
  *ptr = 37;            // то же самое, что var1 = 37;
  var2 = *ptr;          // то же самое, что var2 = var1;

  cout << var2 << endl; // убедимся, что var2 равно 37

  return 0;
}


