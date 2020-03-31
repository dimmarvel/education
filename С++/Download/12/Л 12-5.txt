// iline.cpp
// Файловый ввод (извлечение из файла) строк 
#include <fstream>             // для файловых функций
#include <iostream>
using namespace std;

int main()
  {
  const int MAX = 80;          // размер буфера
  char buffer[MAX];            // буфер символов 
  ifstream infile("TEST.TXT"); // создать входной файл
  while( !infile.eof() )       // цикл до EOF
    {
    infile.getline(buffer, MAX); // читает строку текста
    cout << buffer << endl;      // и выводит ее
    }
  return 0;
 }


