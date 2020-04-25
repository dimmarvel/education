#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Node {
	T data;
	shared_ptr<Node> next;
};

template<typename T>
class DQueue {
	shared_ptr<Node<T>> first;
	shared_ptr<Node<T>> last;
	int size;
public:
	DQueue();				//create queue |	data = NULL	\ next = NULL
	DQueue(T t);			//create queue |	data = t	\ next = new T()
	DQueue(T t, int size);	//create queue |	data = 0	\ next = new T
	~DQueue();				\
	void push();
	void pop();
	void create();
	void OutQueue();
};

template<typename T>
DQueue<T>::DQueue() {
	if(first)
	node.data = 0;
}

template<typename T>
DQueue<T>::DQueue(T t) {
	node.next = new T();
	node.data = t;
}

template<typename T>
DQueue<T>::DQueue(T t, int size) {
	for (int i = 0; i < size; i++)
	{
		node.next = new T();
		node.data = 0;
	}
}

template<typename T>
DQueue<T>::~DQueue() {
	for (size_t i = 0; i < size; i++)
	{
		las
	}
}

template<typename T>
DQueue<T>::OutQueue() {

}

int main() {
	DQueue<int> a();

	system("pause");
}