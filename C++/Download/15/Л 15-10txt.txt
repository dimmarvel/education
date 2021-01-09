// transfo.cpp
// transform() используется для перевода значений из дюймов //в сантиметры
#include <iostream>
#include <algorithm>
using namespace std;

int main()
   {                        // массив дюймов
   double inches[] = { 3.5, 6.2, 1.0, 12.75, 4.33 };
   double centi[5];
   double in_to_cm(double); // прототип
                            // перевод в массив centi[]
   transform(inches, inches+5, centi, in_to_cm);

   for(int j=0; j<5; j++)   // вывод массива centi[]
      cout << centi[j] << ' ';
   cout << endl;
   return 0;
   }

double in_to_cm(double in)  // перевод дюймов в сантиметры
   {
   return (in * 2.54);      // вернуть результат
   }


