#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	float startvklad;
	float years;
	float prosent;
	cout << "������� ��������� �����:";
	cin >> startvklad;
	cout << "������� ����� ���:";
	cin >> years;
	cout << "������� ���������� ������:";
	cin >> prosent;
	prosent = prosent / 100;

	for (int i = 0; i < years; i++) {
		startvklad = startvklad+(startvklad*prosent);
	}


	cout << "����� " << years << "��� �� ��������  = " << startvklad;

	cout << endl;
	system("Pause");
}