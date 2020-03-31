// vectcon.cpp
// демонстрация конструкторов, swap(), empty(), back(), pop_back()
#include <iostream>
#include <vector>
using namespace std;

int main()
   {                                 // массив типа double
   double arr[] = { 1.1, 2.2, 3.3, 4.4 };

   vector<double> v1(arr, arr+4);    // инициализация вектора
                                     //массивом
   vector<double> v2(4);             // пустой вектор. Размер = 4

   v1.swap(v2);                      // обменять содержимое v1 и v2

   while( !v2.empty() )         // пока вектор не будет пуст,
      {
      cout << v2.back() << ' '; // вывести последний элемент
      v2.pop_back();            // и удалить его
      }                         // вывод: 4.4 3.3 2.2 1.1
   cout << endl;
   return 0;
   }


