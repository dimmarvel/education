#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int variant;
	float F, C;
	float res1, res2;
	cout << "������� 1 ���� �������� �� ������� � ����������." << endl;
	cout << "������� 2 ���� �������� �� ���������� � �������." << endl;
	cin >> variant;
	switch (variant) {
		case 1:
		    cout << "������� ����������� �� �������: ";
			cin >> C;
			res1 = C * (9 / 5) + 32;
			cout << "�������� �� ����������: " << res1;
			break;
		case 2:
			cout << "������� ����������� �� ����������: ";
			cin >> F;
			res2 = (F-32)*5/9;
			cout << "�������� �� �������: " << res2;
			break;
        default:
		cout << "����������� ������� �����.";
	}
	cout << endl;
	system("Pause");
}