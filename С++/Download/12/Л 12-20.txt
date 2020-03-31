// ostrstr.cpp
// Запись форматированных данных в память
#include <strstream>
#include <iostream>
#include <iomanip>        // для функции setiosflags()
using namespace std;
const int SIZE = 80;      // размер буфера

int main()
  {
  char ch = 'x';          // тестовые данные
  int j = 77;
  double d = 67890.12345;
  char str1[] = "Kafka";
  char str2[] = "Freud";

  char membuff[SIZE];             // буфер в памяти
  ostrstream omem(membuff, SIZE); // создать потоковый объект
  omem << "ch=" << ch << endl      // вставить форматированные
                                   // данные
      << "j=" << j << endl         // в объект
      << setiosflags(ios::fixed)   // формат с десятичной
                                   // запятой (фиксированной)
      << setprecision(2)           // оставлять два знака после
                                   // запятой
      << "d=" << d << endl
      << "str1=" << str1 << endl
      << "str2=" << str2 << endl
      << ends;         // закончить буфер символом '\0'
  cout << membuff;     // вывод содержимого буфера
  return 0;
  }


