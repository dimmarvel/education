#include<iostream>
using namespace std;
class time {
private:
	int hour;
	int min;
	int sec;
public:

	time() {
		hour = 0;
		min = 0;
		sec = 0;
	}
	time(int h, int m, int s) : hour(h),min(m),sec(s) {}

	void SumTime(time one, time two) {
		hour = one.hour + two.hour;
		min = one.min + two.min;
		if (min > 59) {
			min-=60;
			hour++;
		}
		sec = one.sec + two.sec;
		if (sec > 59) {
			sec -= 60;
			min++;
		}
	}

	void show()const {
		cout << hour << ":" << min << ":" << sec;
	}

};

int main() {
	setlocale(LC_ALL, "Rus");
	time t1(12,42,52);
	time t2(5,25,60);
	time t3;
	t3.SumTime(t1,t2);
	t3.show();
	
	cout << endl;
	system("Pause");
}