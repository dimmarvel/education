// frengl.cpp
// Дружественная перегружаемая операция +
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance                //Класс английских расстояний
  {
  private:
    int feet;
    float inches;
  public:
    Distance()                //конструктор без аргументов
      { feet = 0; inches = 0.0; }
    Distance( float fltfeet ) //конструктор (1 арг.)
      {    //Переводит float в Distance
      feet = int(fltfeet);    //feet – целая часть
      inches = 12*(fltfeet-feet); //слева - дюймы
      }
    Distance(int ft, float in)    //конструктор (2 арг.)
      { feet = ft; inches = in; }
    void showdist()              //Вывести длину
      { cout << feet << "\'-" << inches << '\"';}
    friend Distance operator + (Distance, Distance); //дружественный
  };
//---------------------------------------------------------

Distance operator + (Distance d1, Distance d2) // d1 + d2
  {
  int f = d1.feet + d2.feet;       //+ футы
  float i = d1.inches + d2.inches; //+ дюймы
  if(i >= 12.0)                    //если больше 12 дюймов,
    { i -= 12.0; f++;  }           //уменьшить на 12 дюймов,
                                   //прибавить 1 фут
  return Distance(f,i);            //Новая длина с суммой
  }
//---------------------------------------------------------
int main()
  {
  Distance d1 = 2.5;         //конструктор переводит
  Distance d2 = 1.25;        //float-feet в Distance
  Distance d3;
  cout << "\nd1 = "; d1.showdist(); 
  cout << "\nd2 = "; d2.showdist();

  d3 = d1 + 10.0;            //distance + float: OK
  cout << "\nd3 = "; d3.showdist();
  d3 = 10.0 + d1;            //float + Distance: OK
  cout << "\nd3 = "; d3.showdist();
  cout << endl;
  return 0;
  }


