#include<iostream>
#include<CTYPE.H>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
cout << "���� �� ����� ����� c ������ ��������� �� ����� ����� > 0 � ��������." << endl;
char a;
int b = 1;
while(b > 0){
cin>> a;
cout << islower(a) << endl;
}
system("pause");
}