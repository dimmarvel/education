#include<iostream>

using namespace std;

template<typename T>
class MStack {
private:
	T *pStack;
	int size;
	T top;
public:
	MStack(int = 10);
	~MStack();
	bool push(const T);
	bool pop();
	void printStack();
};

template<typename T>
MStack<T>::MStack(int s)
	:size(s > 0 ? s : 10)
	, pStack(new T[size])
	, top(-1) {
}

template<typename T>
MStack<T>::~MStack() {
	delete[]pStack;
}

template<typename T>
bool MStack<T>::push(const T v) {
	if (top == size - 1)
		return false;
	pStack[++top] = v;
	return true;
}

template<typename T>
bool MStack<T>::pop() {
	if (top == -1)
		return false;
	pStack[top--] = 0;
	return true;
}

template<typename T>
void MStack<T>::printStack() {
	for (int i = 0; i < top; i++)
	{
		cout << pStack[i] << " | ";
	}
}

int main() {
	MStack<int> myStack(5);

	int t = 0;
	while (t++ != 5) {
		int tmp;
		cin >> tmp;
		myStack.push(tmp);
	}

	myStack.printStack();

	cout << "\nDeleted:";
	myStack.pop();
	myStack.pop();
	myStack.printStack();

	system("pause");
	return 0;
}