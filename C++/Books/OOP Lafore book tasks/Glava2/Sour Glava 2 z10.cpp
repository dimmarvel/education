#include<iostream>
#include<cmath> //��� ������� ciel();

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
    float F,SH,P;
	float newpens;
	// 1F = 20SH
	// 1SH = 12P
    cout << "������� ���������� ������: ";
    cin >> F;
	cout << "������� ���������� ���������: ";
	cin >> SH;
	cout << "������� ���������� ������: ";
	cin >> P;
	newpens = (SH*12+P)/2.4;
	//������� ciel(����������) ������������ ��� ���������� �� ������ �����
	cout << "���������� ������: " << "J"<< F << "." << ceil(newpens) << endl;
	system("pause");
}