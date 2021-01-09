// sortemp.cpp
// сортировка массива типа double по убыванию,
// используется функциональный объект greater<>()
#include <iostream>
#include <algorithm>                  //для sort()
#include <functional>                 //для greater<>
using namespace std;
                                      // массив double
double fdata[] = { 19.2, 87.4, 33.6, 55.0, 11.5, 42.2 };

int main()
   {                       // сортировка значений double
   sort( fdata, fdata+6, greater<double>() );

   for(int j=0; j<6; j++)  // вывести отсортированный массив
      cout << fdata[j] << ' ';
   cout << endl;
   return 0;
   }


