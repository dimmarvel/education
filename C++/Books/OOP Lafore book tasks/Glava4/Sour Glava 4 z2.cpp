#include<iostream>
using namespace std;

struct point {
	int p1;
	int p2;
};

	int main() {
		point firstp;
		point secondp;
		setlocale(LC_ALL, "Rus");

		cout << "������� ���������� ����� p1: ";
		cin >> firstp.p1 >> firstp.p2;
		cout << "������� ���������� ����� p2: ";
		cin >>secondp.p1 >> secondp.p2;
		int sump1 = firstp.p1 + secondp.p1;
		int sump2 = firstp.p2 + secondp.p2;

		cout << "���������� ����� �1+�2 �����: " << sump1 << " " << sump2;

		cout << endl;
		system("Pause");
	}