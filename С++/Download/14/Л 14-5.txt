// templist.cpp
// Шаблон связных списков
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
template<class TYPE>      //структура link<TYPE>
struct link               //элемент списка
//( внутри этой структуры определение link означает 
// link<TYPE> )
  {
  TYPE data;              //элемент данных
  link* next;             //указатель на следующий элемент
  };
///////////////////////////////////////////////////////////
template<class TYPE>      //класс linklist<TYPE>
class linklist            //список ссылок
//(внутри этого класса linklist означает linklist<TYPE>)
  {
  private:
    link<TYPE>* first;    //указатель на первую ссылку
  public:
    linklist()            //конструктор без аргументов
      { first = NULL; }   //первой ссылки нет
//примечание: можно вписать еще деструктор; для упрощения //листинга, не приводим его  здесь.
    void additem(TYPE d); //добавить данные (одна ссылка)
    void display();       //вывести все ссылки
  };
///////////////////////////////////////////////////////////
template<class TYPE>
void linklist<TYPE>::additem(TYPE d)    //добавление данных
  {
  link<TYPE>* newlink = new link<TYPE>; //создать новую
                                        // ссылку
  newlink->data = d;      //занести туда данные
  newlink->next = first;  //то есть ссылку на следующий элемент
  first = newlink;        //теперь первая ссылка указывает на
                          //данную ссылку
  }
//---------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::display() //вывод всех ссылок
  {
  link<TYPE>* current = first; //указатель – на первую ссылку
  while( current != NULL )     //выйти после последней ссылки
    {
    cout << endl << current->data; //вывести на экран
    current = current->next;       //сдвинуться на следующую ссылку
    }
  }
//---------------------------------------------------------
int main()
  {
  linklist<double> ld;    //ld - объект linklist<double>

  ld.additem(151.5);      //добавить три числа double в список ld
  ld.additem(262.6);
  ld.additem(373.7);
  ld.display();           //вывести весь список ld

  linklist<char> lch;     //lch - объект linklist<char>

  lch.additem('a');       //три символа (char) – в список lch
  lch.additem('b');
  lch.additem('c');
  lch.display();          //вывести весь список lch
  cout << endl;
  return 0;
  }


