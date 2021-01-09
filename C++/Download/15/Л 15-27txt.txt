// finiter.cpp
// Демонстрация работы istream_iterator с файлами
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
   {
   list<int> iList;               // пустой список
   ifstream infile("ITER.DAT");   // создать входной файловый объект
                                  // (файл ITER.DAT должен уже существовать)
                                  // итераторы istream
   istream_iterator<int> file_iter(infile);  // файл
   istream_iterator<int> end_of_stream;      // eos (конец потока)
                                  // копировать данные из входного файла в iList
   copy( file_iter, end_of_stream, back_inserter(iList) );

   cout << endl;                  // вывести iList
   ostream_iterator<int> ositer(cout, "--");
   copy(iList.begin(), iList.end(), ositer);
   cout << endl;
   return 0;
   }


