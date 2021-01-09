// for_each.cpp
// for_each() используетс€ дл€ вывода элементов массива, //переведенных из дюймов в сантиметры
#include <iostream>
#include <algorithm>
using namespace std;

void in_to_cm(double);   // объ€вление

int main()
   {         // массив значений в дюймах
   double inches[] = { 3.5, 6.2, 1.0, 12.75, 4.33 };
             // вывод в виде сантиметров
   for_each(inches, inches+5, in_to_cm);
   cout << endl;
   return 0;
   }

void in_to_cm(double in) // перевод и вывод в сантиметрах
   {
   cout << (in * 2.54) << ' ';
   }


