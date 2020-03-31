#include <iostream>

using namespace std;
const int SIZE = 10;
struct numb {
	int x;
	int y;
};

class Stack
{
protected:              // Замечание: использовать private нельзя
	enum { MAX = 5 };     // размер стека
	int st[MAX];        // данные, хранящиеся в стеке
	int top;              // индекс последнего элемента в стеке
public:
	Stack()          // конструктор
	{
		top = -1;
	}
	void push(int var) // помещение числа в стек
	{
		st[++top] = var;
	}
	int pop()           // извлечение числа из стека
	{
		return st[top--];
	}
};

class Stack2 : public Stack
{
public:
	void push(int var)      // помещение числа в стек
	{
		if (top >= MAX - 1)  // если стек полон, то ошибка
		{
			cout << "\nОшибка: стек полон"; exit(1);
		}
		Stack::push(var);   // вызов функции push класса Stack
	}
	int pop()                // извлечение числа из стека
	{
		if (top < 0)         // если стек пуст, то ошибка
		{
			cout << "\nОшибка: стек пуст\n"; exit(1);
		}
		return Stack::pop(); // вызов функции pop класса Stack
	}
};
class pairStack : public Stack2, public Stack {
public:
	void push(numb num) {
		Stack2::push(num.x);
		Stack2::push(num.y);
	}
	int pop() {
		return Stack2::pop();
		return Stack2::pop();
	}

};
int main()
{
	setlocale(LC_ALL, "Rus");
	Stack s1;
	pairStack s2;
	numb nu;
	nu.x = 2;
	nu.y = 3;
	cout << nu.x <<endl;
	cout << nu.y <<endl;
	s1.push(22);
	s2.push(nu);
	s2.push(nu);

	cout << endl << s1.pop(); 
	cout << endl << s2.pop(); 
	cout << endl << s2.pop(); 
	cout << endl;
	system("pause");
	return 0;
}



