#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	unsigned int numb = 1; 
	unsigned long fact = 1;

	while(numb !=0){

		cout << "������� ����� �����" << endl;
		cin >> numb;

		for (int j = numb; j > 0; j--) {
			fact *= j;
		}

		if (numb != 0) {
			cout << "Fact = " << fact << endl;
		}

	}
	cout << "�� ����� 0 ���� ����.";

	cout << endl;
	system("Pause");
}