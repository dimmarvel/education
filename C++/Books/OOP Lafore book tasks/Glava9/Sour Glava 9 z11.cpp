#include <iostream>

using namespace std;
const int SIZE = 10;
struct numb {
	int x;
	int y;
};

class Stack
{
protected:              // ���������: ������������ private ������
	enum { MAX = 5 };     // ������ �����
	int st[MAX];        // ������, ���������� � �����
	int top;              // ������ ���������� �������� � �����
public:
	Stack()          // �����������
	{
		top = -1;
	}
	void push(int var) // ��������� ����� � ����
	{
		st[++top] = var;
	}
	int pop()           // ���������� ����� �� �����
	{
		return st[top--];
	}
};

class Stack2 : public Stack
{
public:
	void push(int var)      // ��������� ����� � ����
	{
		if (top >= MAX - 1)  // ���� ���� �����, �� ������
		{
			cout << "\n������: ���� �����"; exit(1);
		}
		Stack::push(var);   // ����� ������� push ������ Stack
	}
	int pop()                // ���������� ����� �� �����
	{
		if (top < 0)         // ���� ���� ����, �� ������
		{
			cout << "\n������: ���� ����\n"; exit(1);
		}
		return Stack::pop(); // ����� ������� pop ������ Stack
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



