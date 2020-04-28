#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
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
	int arr[5] = {10,2,5,10,20};
	vector<int> arr2 = {10,2,5,10,21};

	bool res = equal(begin(arr), end(arr), begin(arr2), end(arr2));

	cout << res << endl;

	auto res2 = mismatch(begin(arr), end(arr), begin(arr2), end(arr2));
	if (res2.first == end(arr) && res2.second == end(arr2)) {
		cout << "+" << endl;
	}
	else {
		cout << "-" << endl;
	}


	system("Pause");
}