#include<iostream>
using namespace std;

struct time {
	int hours;
	int min;
	int sec;
};

int main() {
	setlocale(LC_ALL, "Rus");

	time t1, t2,resultSum;
	char tochie;

	cout << "Input hours\min\sec 1" << endl;
	cin >> t1.hours >> tochie >> t1.min >> tochie >> t1.sec;

	cout << "Input hours\min\sec 2" << endl;
	cin >> t2.hours >> tochie >> t2.min >> tochie >> t2.sec;

	long total1 = t1.hours * 3600 + t1.min * 60 + t1.sec;
	long total2 = t2.hours * 3600 + t2.min * 60 + t2.sec;
	long sum = total1 + total2;

	cout << "sum = " << sum << endl;

	resultSum.hours = sum / (60 * 60);
	resultSum.min = sum % (60 * 60) / 60;
	resultSum.sec = sum % (60 * 60) % 60;

	 cout << "Total SEC = " << sum << endl;

	 cout << "Time in sum = " << resultSum.hours << ":" << resultSum.min << ":" << resultSum.sec;



	cout << endl;
	cout << endl;
	system("Pause");
}