#include<iostream>
using namespace std;

struct fraction {
	int a, b;
	int c, d;
};

int main() {
	setlocale(LC_ALL, "Rus");
	int a1, a2;
	fraction drob1;
	fraction drob2;
	char dummychar;

	cout << "������� ������ �����: ";
	cin >> drob1.a >> dummychar >> drob1.b;


	cout << "������� ������ �����: ";
	cin >> drob2.c >> dummychar >> drob2.d;

	a1 = drob1.a * drob2.d + drob1.b * drob2.c;
	a2 = drob1.b * drob2.d;
	
	cout << "����� ����� " << a1 << "/" << a2;
	cout << endl;
	system("Pause");
}