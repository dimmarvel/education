#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	double SUM, g;
	const double gallon = 7.481;
	cout << "1 ������ = 7,481" << endl;
	cout << "������� ����� ��������:";
	cin >> g;
	SUM = g/gallon;
	cout << "������ � ���������� ����� = " << SUM;
	cout << endl;
	system("Pause");
}