// foutiter.cpp
// Демонстрация работы ostream_iterator с файлами
#include <fstream>
#include <algorithm>
#include <list>
using namespace std;

int main()
   {
   int arr[] = { 11, 21, 31, 41, 51 };
   list<int> theList;      

   for(int j=0; j<5; j++)            //Передача данных 
      theList.push_back( arr[j] );   //из массива в список
   ofstream outfile("ITER.DAT");     //создание файлового объекта

   ostream_iterator<int> ositer(outfile, " "); //итератор
                                     //записать список в файл
   copy(theList.begin(), theList.end(), ositer);
   return 0;
   }


