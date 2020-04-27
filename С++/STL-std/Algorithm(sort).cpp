#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Person {
public:
	Person(string name, double score) {
		this->name = name;
		this->score = score;
	}
	bool operator()(const Person &p) {
		return p.score > 100;
	}
	string name;
	double score;
};

int main() {

	setlocale(LC_ALL, "Rus");
	vector<int> v = { 1,2,4,6,7,23,32,235,12,5 };

	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });

	for (auto elem : v) {
		cout << elem << endl;
	}

	cout << "--------------------------------" << endl;
	int arr[5] = { 1,25,2,412,35 };
	sort(arr, arr + 5);

	for (auto elem : arr) {
		cout << elem << endl;
	}



	cout << "--------------------------------" << endl;

	vector<Person> pers = {
		Person("Grisha", 10),
		Person("Mosha", 20),
		Person("Gosha", 42),
		Person("Catua", 12),
		Person("Kriss", 52),
		Person("Dima", 40),
		Person("Fucker", 24)
	};
	for (auto elem : pers) {
		cout << "Name: \t" << elem.name << "\t score \t" << elem.score << endl;
	}
	cout << "--------------------------------" << endl;
	sort(pers.begin(), pers.end(), [](Person const &pers, Person const &pers2) {
		return pers.name < pers2.name;
	});

	for (auto elem : pers) {
		cout << "Name: \t" << elem.name << "\t score \t" << elem.score << endl;
	}

	system("Pause");
}