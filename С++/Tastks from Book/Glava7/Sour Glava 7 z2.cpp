#include<iostream>
#include<string>
#include<cstring>

using namespace std;
class employee {
private:
	string Name;
	long numb;
public:

	employee() {
	}

	void getdata() {
		cout << "Input Name: ";
		cin >> Name;
		cout << "Input number: ";
		cin >> numb;
	}
	void putdata() {
		cout << "_____________________________________"<< endl;
		cout << "Name - " << Name << endl;
		cout << "Number - " << numb << endl;
	}


};

int main() {
	setlocale(LC_ALL, "Rus");
	employee str[100];
	char yn = 'w';
	int i = 0, onezero = 2;

	do
	{
		cout << "Input Data." << endl;
		str[i++].getdata();
		cout << "Continue? y/n." << endl;
		cin >> yn;
	}while (yn != 'n');

	cout << "Output Data about employ? 0/1" << endl;
	cin >> onezero;
	if (onezero == 1)
	{
		for (int j = 0; j < i; j++) {
			str[j].putdata();
		}
	}
	cout << endl;
	system("Pause");
}