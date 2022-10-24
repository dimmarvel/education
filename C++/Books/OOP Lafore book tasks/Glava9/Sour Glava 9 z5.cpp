#include <iostream>
using namespace std;
const int LEN = 80;       // ������������ ����� �����
///////////////////////////////////////////////////////////
class employee            // ����� ���������
{
private:
	char name[LEN];       // ��� ����������
	unsigned long number; // ����� ����������
public:
	void getdata()
	{
		cout << "\n  ������� �������: "; cin >> name;
		cout << "  ������� �����: ";     cin >> number;
	}
	void putdata() const
	{
		cout << "\n  �������: " << name;
		cout << "\n  �����: " << number;
	}
};
///////////////////////////////////////////////////////////
class employee2 : public employee
{
private:
	double compensations;
	enum etype { hourly, weekly, monthly };
	etype period;
public:
	void getdata()
	{
		employee::getdata();
		char type;
		cout << "\n  ������� �����������: "; cin >> compensations;
		cout << "\n  ������� ������ ������ ������ (������ ����� �� hourly, weekly, monthly): "; cin >> type;
		switch (type)
		{
		case 'h':
			period = hourly; break;
		case 'w':
			period = weekly; break;
		case 'm':
			period = monthly; break;
		}
	}
	void putdata()const
	{
		employee::putdata();
		cout << "\n  �����������: " << compensations;
		cout << "\n  ������ ������ ������ : ";
		switch (period)
		{
		case hourly:
			cout << "��������"; break;
		case weekly:
			cout << "����������"; break;
		case monthly:
			cout << "���������"; break;
		}
	}
};
//////////////////////////////////////////////////////////
class manager : public employee2 // ��������
{
private:
	char title[LEN];      // ���������, �������� ����-���������
	double dues;          // ����� ������� � �����-����
public:
	void getdata()
	{
		employee2::getdata();
		cout << "  ������� ���������: "; cin >> title;
		cout << "  ������� ����� ������� � �����-����: "; cin >> dues;
	}
	void putdata() const
	{
		employee2::putdata();
		cout << "\n  ���������: " << title;
		cout << "\n  ����� ������� � �����-����: " << dues;
	}
};
///////////////////////////////////////////////////////////
class scientist : public employee2 // ������
{
private:
	int pubs;                     // ���������� ����������
public:
	void getdata()
	{
		employee2::getdata();
		cout << "  ������� ���������� ����������: "; cin >> pubs;
	}
	void putdata() const
	{
		employee2::putdata();
		cout << "\n  ���������� ����������: " << pubs;
	}
};
///////////////////////////////////////////////////////////
class laborer : public employee2   // �������
{
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(0, "");
	manager m1, m2;
	scientist s1;
	laborer l1;
	cout << endl;
	cout << "\n���� ���������� � ������ ���������";
	m1.getdata();
	cout << "\n���� ���������� � ������ ���������";
	m2.getdata();
	cout << "\n���� ���������� � ������ ������";
	s1.getdata();
	cout << "\n���� ���������� � ������ �������";
	l1.getdata();
	cout << "\n���������� � ������ ���������";
	m1.putdata();
	cout << "\n���������� � ������ ���������";
	m2.putdata();
	cout << "\n���������� � ������ ������";
	s1.putdata();
	cout << "\n���������� � ������ �������";
	l1.putdata();
	cout << endl;
	system("pause");
	return 0;
}