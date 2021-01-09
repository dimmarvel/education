// ptrinc.cpp
// доступ к массиву через указатель
#include <iostream>
using namespace std;

int main ( )
{
  int intarray [ 5 ] = { 31, 54, 77, 52, 93 }; // набор целых чисел
  int* ptrint;                     // указатель на int
  ptrint = intarray;               // пусть он указывает на наш массив

  for( int j = 0; j < 5; j++ )     // для каждого элемента массива
    cout << *( ptrint++ ) << endl; // напечатаем его значение

  return 0;
}


