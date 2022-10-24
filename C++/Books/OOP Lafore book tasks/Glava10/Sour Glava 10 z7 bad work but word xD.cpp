// persort.cpp
// ���������� �������� ����� ������ ���������� �� ���
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
class person            // ��������� �������
{
protected:
	string name;        // ���
	float salary;
public:
	void setName()    // ��������� �����
	{
		cout << "������� ���: "; cin >> name;
		cout << "������� ������� ��: "; cin >> salary;
	}
	void printData()  // ����� �����
	{
		cout << endl << name;
		cout << endl << salary;
	}
	string getDataS()  // ��������� �����
	{
		return name;
	}
	float getDataF() {
		return salary;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"rus");
	void bsort(person**, int); // �������� �������
	person* persPtr[100];      // ������ ���������� �� person
	int n = 0;                    // ���������� ��������� � �������
	char choice;                  // ���������� ��� ����� �������

	do
	{
		persPtr[n] = new person;       // ������� ����� ������
		persPtr[n]->setName();       // ������ ���
		n++;                              // ����������� ����������
		cout << "���������� ���� (y/n)?"; // ����������, �������� �� ����
		cin >> choice;
	} while (choice == 'y');

	cout << "\n����������������� ������:";
	for (int j = 0; j < n; j++) // ������� ����������������� ������
		persPtr[j]->printData();

	bsort(persPtr, n);         // ����������� ���������

	cout << "\n��������������� ������:";
	for (int j = 0; j < n; j++)     // ������� ��������������� ������
		persPtr[j]->printData();
	cout << endl;
	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////
void bsort(person** pp, int n)
{
	void order(person**, person**); // �������� �������
	int j, k;                          // ���������� ��� ������

	for (j = 0; j < n - 1; j++)      // ������� ����
		for (k = j + 1; k < n; k++)    // ���������� ����
			order(pp + j, pp + k);      // ��������� ��� ��������
}
///////////////////////////////////////////////////////////
void order(person** pp1, person** pp2)
{
	if ((*pp1)->getDataS() > (*pp2)->getDataS()) // ���� ������ ������ ������ ������,
	{
		person* tempptr = *pp1; // ������ �� �������
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}


