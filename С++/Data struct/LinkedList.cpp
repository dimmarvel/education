#include<iostream>
#include<memory>

using namespace std;

template<typename T>
class DLinkList;

template<typename T>
class Node {
public:
	friend class DLinkList<T>;
private:
	T data;
	shared_ptr<Node<T>> next;
public:
	Node() :data(0), next(NULL) {};
	Node(T _data) :data(_data), next(NULL) {};
};

template<typename T>
class DLinkList {

	int size = 0;
	shared_ptr<Node<T>> head;

public:
	DLinkList();
	DLinkList(T _data, int _how = 1);
	void out();
	void add(T _data);
	~DLinkList();
};

template<typename T>
DLinkList<T>::DLinkList()
	: size(0)
	, head(NULL)
{
	cout << "DLinkList()" << endl;
}

template<typename T>
DLinkList<T>::DLinkList(T _data, int _how)
{
	shared_ptr<Node<T>> temp = make_shared<Node<T>>(_data);
	temp->next = NULL;
	for (int i = 0; i < _how; i++)
	{
		if (head == NULL) {
			head = temp;
		}
		else
		{
			shared_ptr<Node<T>> current = make_shared<Node<T>>();
			for (current = head; current->next != 0; current = current->next);
				current->next = temp;
		}
		size++;
		cout << "CONSTRUCTOR Add data(" << _data << ") size(" << size << ")" << endl;
	}
}

template<typename T>
DLinkList<T>::~DLinkList() {
	cout << "~DLinkList()" << endl <<
		"Now size - " <<--size << "(was " << size + 1 << ")";

}

template<typename T>
void DLinkList<T>::out() {
	cout << "void DLinkList<T>::out()" << endl;
	shared_ptr<Node<T>> current = make_shared<Node<T>>();
	current = head;
	int counter = 0;

	while (current->next != NULL) {
		cout << ++counter << " - Data(" << current->data << ")" << endl;
		current = current->next;
	}
	cout << counter++ << " - Data(" << current->data << ")" << endl;

}

template<typename T>
void DLinkList<T>::add(T _data) {
	cout << "void DLinkList<T>::add(T _data)" << endl;
	shared_ptr<Node<T>> temp = make_shared<Node<T>>();
	temp->data = _data;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		cout << "Add data(" << head->data << ") size(" << ++size << ")" << endl;

	}
	else {
		shared_ptr<Node<T>> current = make_shared<Node<T>>();
		current = head;

		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		cout << "Add data(" << current->data << ") size(" << ++size << ")" << endl;
	}
}

int main() {

	shared_ptr<DLinkList<int>> qwe = make_shared<DLinkList<int>>(2);

	qwe->add(5);
	qwe->add(3);

	qwe->add(5);
	qwe->add(3);
	qwe->add(10);
	qwe->add(10);
	qwe->add(10);
	qwe->add(10);
	qwe->out();

	system("pause");
}