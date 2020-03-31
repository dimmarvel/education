// arrnote.cpp
// обычный доступ к элементам массива
#include <iostream>
using namespace std;

int main ( )
{
  int intarray [ 5 ] = { 31, 54, 77, 52, 93 }; // набор целых чисел

  for ( int j = 0; j < 5; j++ )     // для каждого элемента массива
    cout << intarray [ j ] << endl; // напечатаем его значение

  return 0;
}


