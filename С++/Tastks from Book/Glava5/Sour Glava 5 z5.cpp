#include <iostream>
using namespace std;
long hms_to_secs(int, long, long);

int main()
{
	setlocale(LC_ALL, "Rus");
	int hr;
	long mn, sc;
	long sum;
	cout << "input" << endl << "Hours:";
	cin >> hr;
	cout << "Min: ";
	cin >> mn;
	cout << "Sec: ";
	cin >> sc;
	sum = hms_to_secs(hr, mn, sc);

	cout << "All in SEC = " << sum << "sec" << endl;

	system("pause");
}

long hms_to_secs(int  hour, long min, long sec)
{
	long sum;
	sum = hour * 3600 + min * 60 + sec;
	return sum;
}


