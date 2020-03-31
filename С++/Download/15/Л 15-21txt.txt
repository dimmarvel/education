// iterev.cpp
// демонстрация обратного итератора
#include <iostream>
#include <list>
using namespace std;

int main()
   {
   int arr[] = { 2, 4, 6, 8, 10 };    // массив типа int
   list<int> theList;

   for(int j=0; j<5; j++)             // перенести содержимое массива
      theList.push_back( arr[j] );    // в список

   list<int>::reverse_iterator revit; // обратный итератор

   revit = theList.rbegin();          // реверсная итерация
   while( revit != theList.rend() )   // по списку
      cout << *revit++ << ' ';        // с выводом на экран
   cout << endl;
   return 0;
   }


