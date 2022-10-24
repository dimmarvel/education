//VARIANT 1
/*#include<iostream>
using namespace std;
void counters(int&);
int main() {
	setlocale(LC_ALL, "Rus");

	int some, counter = 0;
	do{
	cout << "Counter call of function = " << counter << endl;
	cin >> some;
	counters(counter);
	}while(some !=0);

	system("Pause");
}
void counters(int& counter) {
	counter++;
}

*/
//VARIANT 2
#include<iostream>
using namespace std;
int counter = 0;
void counters();
int main() {
	setlocale(LC_ALL, "Rus");

	int some;
	do {
		cout << "Counter call of function = " << counter << endl;
		cin >> some;
		counters();
	} while (some != 0);

	system("Pause");
}
void counters() {
	++counter;
}
