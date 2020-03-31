// temstak2.cpp
// реализует стековый класс в виде шаблона
// методы определ€ютс€ вне класса
#include <iostream>
using namespace std;
const int MAX = 100;
/////////////////////////////////////////////////////////////
template <class Type>
class Stack
  {
  private:
    Type st[MAX];         //стек Ц массив любого типа
    int top;              //индекс вершины стека
  public:
    Stack();              //конструктор
    void push(Type var);  //занести число в стек
    Type pop();           //вз€ть число из стека
  };
/////////////////////////////////////////////////////////////
template<class Type>
Stack<Type>::Stack()      //конструктор
  {
  top = -1;
  }
//-----------------------------------------------------------
template<class Type>
void Stack<Type>::push(Type var) //положить число в стек
  {
  st[++top] = var;
  }
//-----------------------------------------------------------
template<class Type>
Type Stack<Type>::pop()          //вз€ть число из стека
  {
  return st[top--];
  }
//-----------------------------------------------------------

int main()
  {
  Stack<float> s1;        //s1 Ц объект класса Stack<float>

  s1.push(1111.1F);       //занести 3 float, вытолкнуть 3 float
  s1.push(2222.2F);
  s1.push(3333.3F);
  cout << "1: " << s1.pop() << endl;
  cout << "2: " << s1.pop() << endl;
  cout << "3: " << s1.pop() << endl;

  Stack<long> s2;         //s2 Ц объект класса Stack<long>

  s2.push(123123123L);    //занести 3 long, вытолкнуть 3 long
  s2.push(234234234L);
  s2.push(345345345L);
  cout << "1: " << s2.pop() << endl;
  cout << "2: " << s2.pop() << endl;
  cout << "3: " << s2.pop() << endl;
  return 0;
  }


