#include<iostream>
using namespace std;
const double pi = 3.14159f;
float circarea(float n) {
		const float pi = 3.14159f;
		return pi * n * n;
};

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Input circle radius";
	double n;
	cin >> n;
	cout << "S = " << circarea(n);

	cout << endl;
	system("Pause");
}