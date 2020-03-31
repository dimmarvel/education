// ptrvoid.cpp
// указатель на void
#include <iostream>
using namespace std;

int main ( )
{
  int intvar;           // целочисленная переменная
  float flovar;         // вещественная переменная

  int* ptrint;          // указатель на int
  float* ptrflo;        // указатель на float
  void* ptrvoid;        // указатель на void

  ptrint = &intvar;     // так можно: int* = int*
//ptrint = &flovar;     // так нельзя: int* = float*
//ptrflo = &intvar;     // так нельзя: float* = int*
  ptrflo = &flovar;     // так можно: float* = float*

  ptrvoid = &intvar;    // так можно: void* = int*
  ptrvoid = &flovar;    // так можно: void* = float*

  return 0;
}


