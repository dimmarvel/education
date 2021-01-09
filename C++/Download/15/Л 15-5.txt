// merge.cpp
// соединение двух контейнеров в третий
#include <iostream>
#include <algorithm>          //для merge()
using namespace std;

int src1[] = { 2, 3, 4, 6, 8 };
int src2[] = { 1, 3, 5 };
int dest[8];

int main()
   {                          //соединить src1 и src2 в dest
   merge(src1, src1+5, src2, src2+3, dest);
   for(int j=0; j<8; j++)     // вывести dest
      cout << dest[j] << ' ';
   cout << endl;
   return 0;
   }


