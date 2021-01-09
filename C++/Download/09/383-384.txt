// pubpriv.cpp
// испытание классов наследованных как public и private
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class A                // базовый класс
{
  private:             // тип доступа к данным совпадает с типом
    int privdataA;     // доступа к функциям
  protected:
    int protdataA;
  public:
    int pubdataA;
};
///////////////////////////////////////////////////////////
class B : public A     // public наследование
{
  public:
    void funct ( )
      {
        int a;
        a = privdataA; // ошибка, нет доступа
        a = protdataA; // так можно
        a = pubdataA;  // так можно
      }
};
///////////////////////////////////////////////////////////
class C : private A    // private наследование
{
  public:
    void funct ( )
      {
        int a;
        a = privdataA; // ошибка, нет доступа
        a = protdataA; // так можно
        a = pubdataA;  // так можно
      }
};
///////////////////////////////////////////////////////////
int main ( )
{
  int a;
  B objB;
  a = objB.privdataA;  // ошибка, нет доступа
  a = objB.protdataA;  // ошибка, нет доступа
  a = objB.pubdataA;   // так можно

  c objC;
  a = objC.privdataA;  // ошибка, нет доступа
  a = objC.protdataA;  // ошибка, нет доступа
  a = objC.pubdataA;   // ошибка, нет доступа

  return 0;
}


