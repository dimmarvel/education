// frisq.cpp
// Дружественная для Distance функция square()
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance                        //Класс английских длин
  {
  private:
    int feet;
    class Distance                    //Класс английских длин
  {
  private:
    int feet;
    float inches;
  public:
    Distance() : feet(0), inches(0.0) //конструктор (без
                                      //аргументов) 
      {  }
                                   //конструктор (2 аргумента)
    Distance(int ft, float in) : feet(ft), inches(in)  
      {  }
    void showdist()                //вывести расстояние
      { cout << feet << "\'-" << inches << '\"'; }
    friend float square(Distance); //дружественная ф-ция
  };
//---------------------------------------------------------
float square(Distance d)                //вернуть квадрат
  {                                     //расстояния
  float fltfeet = d.feet + d.inches/12; //конвертировать 
                                        //в тип float
  float feetsqrd = fltfeet * fltfeet;   //вычислить квадрат
  return feetsqrd;                      //вернуть квадратные футы
  }
///////////////////////////////////////////////////////////
int main()
  {
  Distance dist(3, 6.0);             //конструктор с двумя 
                                     //аргументами (3'-6")
  float sqft;

  sqft = square(dist);               //вернуть квадрат dist
                         //Вывести расстояние и его квадрат
  cout << "\nРасстояние = "; dist.showdist();
  cout << "\nКвадрат расст. = " << sqft << " square feet\n";
  return 0;
  }
float inches;
  public:                   //конструктор (без аргументов)
    Distance() : feet(0), inches(0.0)  
{  }                        //constructor (two args)
  Distance(int ft, float in) : feet(ft), inches(in) 
      {  }
    void showdist()         //показать длину
      { cout << feet << "\'-" << inches << '\"';}
    float square();         //обычный метод
  };
//---------------------------------------------------------
float Distance::square()              //возвращает квадрат
  {                                   //расстояния
  float fltfeet = feet + inches/12;   //перевод во float
  float feetsqrd = fltfeet * fltfeet; //возведение в
                                      //квадрат
  return feetsqrd;                    //возвратить квадрат
  }
///////////////////////////////////////////////////////////
int main()
  {
  Distance dist(3, 6.0);   //конструктор с двумя арг. (3'-6")
  float sqft;

  sqft = dist.square();    //вычислить квадрат расстояния
                           //показать расст. и квадрат расст. 
  cout << "\nРасстояние = "; dist.showdist();
  cout << "\nКвадрат расст. = " << sqft << " кв. футов\n";
  return 0;
  }


