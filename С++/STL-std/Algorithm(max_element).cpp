#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
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

	list<int> lst = {4,6,2,8,3,5,1,222,414,5125,1,25,6,36,6126};

	auto it = max_element(v.begin(),v.end());
	auto it5 = min_element(v.begin(),v.end());
	cout << "Max - " << *it << endl;
	cout << "Min - " << *it5 << endl;
	for (auto elem : v) {
		cout << elem << endl;
	}
	cout << "--------------------------------" << endl;

	auto it2 = max_element(lst.begin(), lst.end());
	auto it3 = min_element(lst.begin(), lst.end());
	cout << "Max - " << *it2 << endl;
	cout << "Min - " << *it3 << endl;
	for (auto elem : lst) {
		cout << elem << endl;
	}

	auto it0 = minmax_element(lst.begin(), lst.end());
	cout << "First: " << *it0.first << " Second: " << *it0.second << endl;

	system("Pause");
}