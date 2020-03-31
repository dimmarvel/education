#include<iostream>
using namespace std;


struct time {
	long hours;
	long min;
	long sec;
};
time resultSum;
long sum;
time secs_to_time(time ReturnInSec);
long time_to_secs(time sec);

int main() {
	setlocale(LC_ALL, "Rus");

	long total1;
	long total2;
	time t1, t2;
	char tochie;
	cout << "Input hours\min\sec 1" << endl;
	cin >> t1.hours >> tochie >> t1.min >> tochie >> t1.sec;

	cout << "Input hours\min\sec 2" << endl;
	cin >> t2.hours >> tochie >> t2.min >> tochie >> t2.sec;

	total1 = time_to_secs(t1);
	total2 = time_to_secs(t2);
	sum = total1 + total2;

	cout << "sum = " << sum << endl;

	resultSum = secs_to_time(resultSum);

	cout << "Total SEC = " << sum << endl;

	cout << "Time in sum = " << resultSum.hours << ":" << resultSum.min << ":" << resultSum.sec;

	cout << endl;
	cout << endl;
	system("Pause");
}
long time_to_secs(time second) {
	long sum;
	sum = second.hours * 3600 + second.min * 60 + second.sec;
	return sum;
}
time secs_to_time(time ReturnInSec){
	ReturnInSec.hours = sum / (60 * 60);
	ReturnInSec.min = sum % (60 * 60) / 60;
	ReturnInSec.sec = sum % (60 * 60) % 60;
	return ReturnInSec;
}


