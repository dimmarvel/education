// ptrvar.cpp
// указатели (адреса переменных)
#include <iostream>
using namespace std;

int main ( )
{
  int var1 = 11;        // две переменные
  int var2 = 22;

  cout << &var1 << endl // покажем адреса переменных
       << &var2 << endl << endl;

  int* ptr; // это переменная-указатель на целое

  ptr = &var1;          // присвоим ей значение адреса var1
  cout << ptr << endl;  // и покажем на экране

  ptr = &var2;          // теперь значение адреса var2
  cout << ptr << endl;  // и покажем на экране

  return 0;
}


