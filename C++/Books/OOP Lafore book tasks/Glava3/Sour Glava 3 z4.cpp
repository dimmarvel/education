#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	char operaciya, division = '/', pluse = '+', minus = '-';
	double otvet, perem1,perem2;
	bool y = true;

	while (y) {

		cout << "������� ������ �������, �������� � ������ �������" << endl;
		cin >> perem1 >> operaciya >> perem2;

		switch (operaciya) {
			case '+': otvet = perem1 + perem2;
			cout << "�����: " << otvet << endl;
			    break;
			case '-': otvet = perem1 - perem2;
			cout << "�����: " << otvet << endl;
				break;
			case '/': otvet = perem1 / perem2;
			cout << "�����: " << otvet << endl;
				break;
			default:
			cout << "������� ���������� ���" << endl;
		}

		cout << "������ ��������� ��� ���� ��������(�/n)?" << endl;

		char yn;
		cin >> yn;

		if (yn == 'n') {
			y = false;
			cout << "End work programm.";
		}
	}
	cout << endl;
	system("Pause");
}