// passarr.cpp
// передача массива по указателю
#include <iostream>
using namespace std;
const int MAX = 5;            // количество элементов в массиве

int main ( )
{
  void centimize ( double* ); // прототип функции

  double varray [ MAX ] = { 10.0, 43.1, 95.9, 58.7, 87.3 };

  centimize( varray );        // переводим все элементы массива в сантиметры

  // покажем, что у нас получилось
  for ( int j = 0; j < MAX; j++ )
    cout << "varray [ " << j << " ] = " << varray [ j ] << " сантиметров" << endl;

  return 0;
}
///////////////////////////////////////////////////////////
void centimize ( double* ptrd )
{
  for ( int j = 0; j < MAX; j++ )
    *ptrd++ *= 2.54;
}


