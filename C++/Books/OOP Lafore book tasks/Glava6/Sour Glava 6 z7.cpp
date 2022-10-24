#include<iostream>
using namespace std;

class angle {
private:
	int degrees; //градусы
	float min;
	char NSEW;
public:
	angle() {}
	angle(int d, float m, char N) : degrees(d), min(m), NSEW(N) {}
	void getinfo() {
		cout << "Input degrees" << endl;
		cin >> degrees;
		cout << "Input min" << endl;
		cin >> min;
		cout << "Input NSEW" << endl;
		cin >> NSEW;
	}
	void showinfo() {
		while (min > 59.9) {
			if (min > 59.9) {
				degrees++;
				min -= 60;
			}
		}
		cout << degrees << "\xF8" << min << "' " << NSEW << endl;
	}
};
int main() {
	//setlocale(LC_ALL, "Rus");
	angle automat(23, 24.5, 'N');
	angle angls1;
	automat.showinfo();
	int inp;
	do {
		angls1.getinfo();
		angls1.showinfo();
		cout << "More? y-1 n-0\n";
		cin >> inp;
	} while (inp != 0);
	cout << endl;
	system("Pause");
}