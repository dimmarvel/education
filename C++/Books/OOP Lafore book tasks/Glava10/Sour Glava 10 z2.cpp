// newstr.cpp
// ������������� ��������� new ��� ��������� ������ ��� ������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
///////////////////////////////////////////////////////////
class String
{
private:
	char* str;          // ��������� �� ������
public:
	String(const char* s)  // ����������� � ����� ����������
	{
		int length = strlen(s);     // ��������� ����� ������
		str = new char[length + 1]; // �������� ����������� ������
		strcpy(str, s);             // �������� ������
	}
	~String()         // ����������
	{
		cout << "������� ������\n";
		delete[] str; // ����������� ������
	}
	void display()    // ������� ������ �� ������
	{
		cout << str << endl;
	}
	void upit()
	{
		int length = strlen(this->str);
		for (int i = 0; i < length; i++)
		{
			this->str[i] = toupper(this->str[i]);
		}
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	String s1 = "���� ����� � ������ ������.";
	cout << "s1 = ";
	s1.display();
	s1.upit();
	s1.display();
	system("pause");
	return 0;
}


