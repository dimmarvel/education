#include<iostream>
using namespace std;
class time {
private:
	int hour;
	int min;
	int sec;
public:
	time() { hour = 0; min = 0; sec = 0; }
	time(int h, int m, int s) : hour(h), min(m), sec(s) {}

	time operator+ (time two) {
		time temp;
		temp.hour = hour + two.hour;
		temp.min = min + two.min;
		temp.sec = sec + two.sec;
		if (temp.min > 59) {
			temp.min -= 60;
			temp.hour++;
		}
		if (temp.sec > 59) {
			temp.sec -= 60;
			temp.min++;
		}
		return temp;
	}
	time operator- (time two) {
		time temp;
		temp.hour = hour - two.hour;
		temp.min = min - two.min;
		temp.sec = sec - two.sec;
		if (temp.min > 59) {
			temp.min -= 60;
			temp.hour++;
		}
		if (temp.sec > 59) {
			temp.sec -= 60;
			temp.min++;
		}
		if (temp.min < 0) {
			if (temp.hour > 0) {
				--temp.hour;
				temp.min += 60;
			}
			else {
				cout << "Error min < 0";
			}
		}
		if (temp.sec < 0) {
			if (temp.min > 0) {
				--temp.min;
				temp.sec += 60;
			}
			else if (temp.hour > 0) {
				--temp.hour;
				temp.min +=60;
				temp.sec +=60;
			}
			else {
				cout << "Error sec < 0";
			}
		}
		return temp;
	}
	time operator* (time two) {
		time temp;
		temp.hour = hour * two.hour;
		temp.min = min * two.min;
		temp.sec = sec * two.sec;
		if (temp.min > 59) {
			temp.min -= 60;
			temp.hour++;
		}
		if (temp.sec > 59) {
			temp.sec -= 60;
			temp.min++;
		}

		return temp;
	}
	time operator++ () {
		return time(++hour, ++min, ++sec);
	}
	time operator--() {
		return time(--hour, --min, --sec);
	}
	time operator++ (int) {
		return time(hour++, min++, sec++);
	}
	time operator-- (int) {
		return time(hour--, min--, sec--);
	}

	void show()const {
		cout << hour << ":" << min << ":" << sec << endl;
	}

};

int main(){
	setlocale(LC_ALL, "Rus");
	time time_1(3, 2, 2), time_2(2, 6, 1);
	time time_sum, temp;
	time_sum = time_1 + time_2;
	time_1.show();
	time_2.show();
	cout << "+ = ";  time_sum.show();
	cout << "++qwe = "; ++time_sum; time_sum.show();
	cout << "--qwe = "; --time_sum; time_sum.show();
	cout << "qwe++ = "; temp = time_sum++; temp.show();
	cout << "qwe-- = "; temp = time_sum--; temp.show();
	cout << "- = "; time_sum = time_1 - time_2; time_sum.show();
	cout << "* = "; time_sum = time_1 * time_2; time_sum.show();
	system("pause");

	cout << endl;
	system("Pause");
}