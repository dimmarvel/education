// listplus.cpp
// ƒемонстраци€ методов reverse(), merge() и unique()
#include <iostream>
#include <list>
using namespace std;

int main()
   {
   int j;
   list<int> list1, list2;

   int arr1[] = { 40, 30, 20, 10 };
   int arr2[] = { 15, 20, 25, 30, 35 };

   for(j=0; j<4; j++)
      list1.push_back( arr1[j] );   // list1: 40, 30, 20, 10
   for(j=0; j<5; j++)
      list2.push_back( arr2[j] );   // list2: 15, 20, 25, 30, 35

   list1.reverse();                 // перевернуть list1: 10 20 30 40
   list1.merge(list2);              // объединить list2 с list1
   list1.unique();                  // удалить повтор€ющиес€ элементы 20 и 30

   int size = list1.size();
   while( !list1.empty() )
      {
      cout << list1.front() << ' '; // читать элемент из
                                    //начала
      list1.pop_front();            // вытолкнуть элемент из начала
      }
   cout << endl;
   return 0;
   }


