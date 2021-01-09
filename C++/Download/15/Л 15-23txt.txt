// dinsiter.cpp
// Очереди и итераторы вставки
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
   {
   int arr1[] = { 1, 3, 5, 7, 9 };  //инициализация d1
   int arr2[] = {2, 4, 6};          //инициализация d2
   deque<int> d1;
   deque<int> d2;

   for(int i=0; i<5; i++)           //перенести данные из массивов в
                                    //очереди с двусторонним доступом
      d1.push_back( arr1[i] );
   for(int j=0; j<3; j++)
      d2.push_back( arr2[j] );
                                    //копировать d1 в конец d2
   copy( d1.begin(), d1.end(), back_inserter(d2) );

   cout << "\nd2: ";                //вывести d2
   for(int k=0; k<d2.size(); k++)
      cout << d2[k] << ' ';
   cout << endl;
   return 0;
   }


