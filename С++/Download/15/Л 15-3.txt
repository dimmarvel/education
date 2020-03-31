// sort.cpp
// сортирует массив целых чисел
#include <iostream>
#include <algorithm>
using namespace std;
                           // массив чисел
int arr[] = {45, 2, 22, -17, 0, -30, 25, 55};

int main()
   {
   sort(arr, arr+8);       // сортировка

for(int j=0; j<8; j++)    // вывести отсортированный
                          //массив
      cout << arr[j] << ' ';
   cout << endl;
   return 0;
   }


