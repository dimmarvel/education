#include<iostream>
using namespace std;
class tollBooth {
private:
	unsigned int AutoCount;
	double SumViruchka;
public:

	tollBooth() {
		AutoCount = 0;
		SumViruchka = 0;
	}

	void PayingCar() {
		AutoCount++;
		SumViruchka += 0.5;
	}
	void NoPayingCar() {
		AutoCount++;
	}
	void show()const {
		cout << "����� �������: " << SumViruchka << "\n";
		cout << "����� �������� �����: " << AutoCount << "\n";
	}

};

int main() {
	setlocale(LC_ALL, "Rus");
	int input;
	tollBooth Kassa;
	cout << "���� ������ �������� �� �������� ������� 1\n";
	cout << "���� ������ �������� �������� ������� 2\n";
	cout << "���� ������ ������ ������� 3\n";
	cout << "���� ������ ��������� ��������� ������� 0\n";
	do {
		cin >> input;
		switch (input)
		{
		case 1: Kassa.NoPayingCar(); break;
		case 2: Kassa.PayingCar(); break;
		case 3: Kassa.show(); break;
		}
	} while (input != 0);

	cout << endl;
	system("Pause");
}