// list.cpp
// демонстрация методов push_front(), front(), pop_front()
#include <iostream>
#include <list>
using namespace std;

int main()
   {
   list<int> ilist;

   ilist.push_back(30);     // вставка элементов в конец
   ilist.push_back(40);
   ilist.push_front(20);    // вставка элементов в начало
   ilist.push_front(10);

   int size = ilist.size(); // число элементов

   for(int j=0; j<size; j++)
      {
      cout << ilist.front() << ' ';  // читать данные
                                     //из начала
      ilist.pop_front();    // извлечение данных из начала
      }
   cout << endl;
   return 0;
   }


