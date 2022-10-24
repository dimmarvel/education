/*
	����������� ����� Distance �� ��������� ENGLCON, ����� 6 �������� �
	�������. ��������� ����, ����������� ����������� � ��������� DISKFUN
	� ���� �����, �������� ��������� �������� �� ������������ � ��������
	�� � ����. �������� �� � ��� ���������� ��� ������ (��� �� �������).
	��� ��������� ������������� ����� ���������� ���� � �������� �� ����� ��� ��������.
*/
#include<iostream>
#include<fstream>
using namespace std;
class Distance           
{
private:
	int feet;
	float inches;
public:                  
	Distance() : feet(0), inches(0.0) {}
	Distance(int ft, float in) : feet(ft), inches(in){}
	void getdist()         
	{
		cout << "\n������� ����� �����: "; cin >> feet;
		cout << "������� ����� ������: "; cin >> inches;
	}
	void showdist()          // ����� ����� �� �����
	{
		cout << feet << "\'-" << inches << '\"';
	}
	void add_dist(Distance, Distance);            // ��������
};

void Distance::add_dist(Distance dd1, Distance dd2)
{
	inches = dd1.inches + dd2.inches;      // �������� ������
	feet = 0;                              // � ��������� ������
	if (inches >= 12.0)                     // ���� ����� ������ ������ 12.0,
	{                                      // �� ��������� ����� ������
		inches -= 12.0;                      // �� 12.0 � �����������
		feet++;                              // ����� ����� �� 1
	}
	feet += dd1.feet + dd2.feet;           // �������� �����
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Distance dist1;
	fstream obj("DISTANCEDATA.DAT", ios::in | ios::app | ios::binary | ios::out);
	char ch = 'n';
	do {
		cout << "\nInput data: ";
		dist1.getdist();
		obj.write(reinterpret_cast<char*>(&dist1), sizeof(dist1));
		cout << "Continue?(y|n)" << endl;
		cin >> ch;
	} while (ch != 'n');
	obj.seekg(0);

	obj.read(reinterpret_cast<char*>(&dist1), sizeof(dist1));
	while (obj) {
		cout << "Dist: ";
		dist1.showdist();
		obj.read(reinterpret_cast<char*>(&dist1), sizeof(dist1));
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
