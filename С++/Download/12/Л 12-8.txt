// ichar2.cpp
// Файловый ввод символов
#include <fstream>             // для файловых функций
#include <iostream>
using namespace std;

int main()
  {
  ifstream infile("TEST.TXT"); // создать входной файл

  cout << infile.rdbuf();      // передать его буфер в cout
  cout << endl;
  return 0;
  }


