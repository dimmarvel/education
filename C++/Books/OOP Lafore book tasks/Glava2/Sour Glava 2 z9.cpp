#include<iostream>
#include<iomanip>
using namespace std;

int main() {
 setlocale(LC_ALL, "Rus");

 int a,b,c,d;
 double a1, a2;
 char dummychar;

 cout << "������� ������ �����: ";
 cin >> a >> dummychar >> b;

 
 cout << "������� ������ �����: ";
 cin >> c >> dummychar >> d;

 a1 = a*d+b*c; //���������
 a2 = d*b; //�����������


 cout << "����� ����� " << a1 << "/" << a2;

 cout << endl;
 system("Pause");
}