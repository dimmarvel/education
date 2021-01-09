// newintro.cpp
// познакомимся с оператором new
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;

int main()
{

	setlocale(LC_ALL, "Rus");
	const char* str = "Smth text like that";
	int len = strlen(str);
	char* ptr = new char[len+1];

	strcpy(ptr,str);
	cout << ptr << endl;
	delete [] ptr;
	system("pause");
	return 0;

}



