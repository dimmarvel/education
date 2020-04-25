#include <iostream>
#include <list>
#include <memory>
#include <iterator>

using namespace std;

template<typename T>
class DQueue {
	
	int size;
	list<T> lst;

public:
	
	DQueue();					
	explicit DQueue(T _val, int size = 1);

	~DQueue();	

	void push_back(T _val);
	void push_front(T _val);
	void pop_back();
	void pop_front();
	void Out();

};

template<typename T>
DQueue<T>::DQueue() : lst(lst.push_back(0)) {}

template<typename T>
DQueue<T>::DQueue(T _val, int size) {
	
	for (int i = 0; i < size; i++)
		lst.push_back(_val);

	this->size += size;
}

template<typename T>
DQueue<T>::~DQueue() {
	for (int i = 0; i < size; i++)
		lst.pop_back();
	size = 0;
}

template<typename T>
void DQueue<T>::Out() {

	for (auto iter = lst.begin(); iter != lst.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

template<typename T>
void DQueue<T>::pop_back() {
	cout << "Pop_front( " << lst.end() << " size(" << --size << ")" << endl;
	lst.pop_back();
}

template<typename T>
void DQueue<T>::pop_front() {
	cout << "Pop_front( " << lst.front() << " size(" << --size << ")" << endl;
	lst.pop_back();
}

template<typename T>
void DQueue<T>::push_back(T _val) {
	size++;
	lst.push_back(_val);
	cout << "Push_back( " << _val << " size(" << size << ")" << endl;
}

template<typename T>
void DQueue<T>::push_front(T _val) {
	size++;
	lst.push_front(_val);
	cout << "Push_front( " << _val << " size(" << size << ")" << endl;
}

int main() {
	DQueue<int> a(10,5);
	a.Out();

	a.pop_back();
	a.pop_front();
	a.push_front(9);
	a.push_back(8);

	a.Out();

	system("pause");
}