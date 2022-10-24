/*
	4.	� ����� ������������ � ������������ ������, ��������� �� �����, ������-
��, ������� � ������ ��������� (���� unsigned long). ����� �����������
��������������� ����� � ������ ofstream � ������� ��������� �������
(<<). �� ���������, ��� ������ ������ ������ ������������ ���������
��� ������� �������������. ����� ������������ ������� �� ���������
�����, �������� ������ ofstream, �������� ������ ifstream, ���������� � ��-
������ �� ����� ��� ������ �� �����, ����� ���� ��������� ���������.

*/
#include<iostream>
#include<fstream>
using namespace std;
class persons {
private:
	char name[50];
	char fam[50];
	char otch[50];
	unsigned long number;
public:
	persons():name(""),fam(""),otch(""),number(1){}

	friend istream& operator >>(istream& s, persons& p);
	friend ostream& operator <<(ostream& s, persons& p);
};
istream& operator >> (istream& s, persons& p) {
	cout << "Input:" << endl;
	cout << "Name: "; s >> p.name;
	cout << "Fam: "; s >> p.fam;
	cout << "Otch: "; s >> p.otch;
	cout << "Number pers: "; s >> p.number;
	return s;
}
ostream& operator << (ostream& s, persons& p) {
	s << "���: " << p.name << endl;
	s << "�������: " << p.fam << endl;
	s << "��������: " << p.otch << endl;
	s << "�����: " << p.number << endl;
	return s;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	persons obj,obj2;
	cin >> obj;
	cin >> obj2;
	cout << obj;
	cout << obj2;
	system("pause");
	return 0;
}
