// strplus.cpp
// ���������� �������� + ��� �����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h>   // ��� ������� strcpy, strcat
#include <stdlib.h>   // ��� ������� exit
///////////////////////////////////////////////////////////
class String          // ��� ����� ��� �����
{
private:
	enum { SZ = 80 }; // ������������ ������ ������
	char str[SZ];  // ������ ��� ������
public:
	// ����������� ��� ����������
	String()
	{
		strcpy(str, "");
	}
	// ����������� � ����� ����������
	String(const char s[])
	{
		strcpy(str, s);
	}
	// ����� ������
	void display() const
	{
		cout << str;
	}
	String operator+= (String s22)
	{
		if (strlen(str) + strlen(s22.str) < SZ)
		{
			strcat(str, s22.str); // ��������� ���������� ������ ������
		}
		else
		{
			cout << "\n������������!";
			exit(1);
		}
		return String(str);  // ���������� ���������
	}
};
///////////////////////////////////////////////////////////
int main()
{

	setlocale(LC_ALL, "Rus");
	String s1 = "����������!"; // ���������� ����������� � ����������
	String s2 = "� ����� �����!";   // ���������� ����������� � ����������
	String s3;   // ���������� ����������� � ����������

	// ���������� ������
	cout << "s1 "; s1.display();
	cout << "s2 "; s2.display();

	s3 = s1 += s2;       // ����������� ������ s3 ��������� �������� ����� s1 � s2

	cout << "s3 "; s3.display();     // ���������� ���������
	cout << endl;
	system("pause");
	return 0;
}


