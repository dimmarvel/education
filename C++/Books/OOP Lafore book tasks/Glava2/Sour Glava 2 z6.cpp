#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
    double Doll = 1.487, Frank = 0.172, GermanyMark = 0.584, Yena = 0.00955;
    double funt;
	cout << "������� ���������� ������: ";
	cin >> funt;
	cout << "���� �� 1 ����." << endl;
	cout << "� ��������: " << funt * Doll << "$" << endl;
	cout << "� �������: " << funt * Frank << "$" << endl;
	cout << "� �������� �����: " << funt * GermanyMark << "$" << endl;
	cout << "� �������� �����: " << funt * Yena << "$" << endl;
	system("pause");
}