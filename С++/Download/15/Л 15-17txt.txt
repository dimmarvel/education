// listout.cpp
// итератор и цикл for для вывода данных
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
   {
   int arr[] = { 2, 4, 6, 8 };
   list<int> theList;

   for(int k=0; k<4; k++)            //заполнить список элементами
      theList.push_back( arr[k] );   // массива

   list<int>::iterator iter;         //итератор для целочисленного
                                     //списка

   for(iter = theList.begin(); iter != theList.end(); iter++)
      cout << *iter << ' ';          //вывести список
   cout << endl;
   return 0;
   }


