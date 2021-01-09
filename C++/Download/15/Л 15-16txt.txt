// deque.cpp
// Демонстрация методов push_back(), push_front(), front()
#include <iostream>
#include <deque>
using namespace std;

int main()
   {
   deque<int> deq;

   deq.push_back(30);          // проталкивание элементов в конец
   deq.push_back(40);
   deq.push_back(50);
   deq.push_front(20);         // проталкивание элементов в начало
   deq.push_front(10);

   deq[2] = 33;                // изменение произвольного элемента контейнера

   for(int j=0; j<deq.size(); j++)
      cout << deq[j] << ' ';   // вывести элементы
   cout << endl;
   return 0;
   }


