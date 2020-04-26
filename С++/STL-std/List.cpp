#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<typename T>
void PrintList(const list<T>& lst) {
	for (auto i = lst.cbegin(); i != lst.cend(); ++i)
		cout << *i << " ";
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");

	list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(3);
	lst.push_back(3);
	lst.push_front(10);
	lst.push_front(9);
	lst.push_front(9);
	lst.push_front(3);
	lst.push_front(8);

	//lst[1]; ERROR

	auto it = lst.begin();
	cout << "it - " << *it << endl;

	cout << "Elements: ";
	PrintList(lst);
	cout << "Sort: ";
	lst.sort();
	PrintList(lst);

	cout << "Pop_back: ";
	lst.pop_back();
	PrintList(lst);

	cout << "Unique (удаляет только последовательно идущие дубликаты): ";
	lst.unique();
	PrintList(lst);

	cout << "Reverse: ";
	lst.reverse();
	PrintList(lst);

	cout << "Insert(++it,111): ";
	lst.insert(++it, 111);
	PrintList(lst);
	
	
	cout << "Erase(++it): ";
	lst.erase(++it);
	PrintList(lst);	


	cout << "Remove(111): ";
	lst.remove(111);
	PrintList(lst);

	list<int> arr2 = { 2,4,6,8,9,2 };
	cout << "Arr2 assign(begin,end): ";
	arr2.assign(lst.begin(), lst.end());
	PrintList(arr2);

	cout << "assign(3,321123): ";
	lst.assign(3,321123);
	PrintList(lst);

	system("Pause");
}