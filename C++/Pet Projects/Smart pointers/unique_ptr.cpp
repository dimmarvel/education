//my simple unique_ptr
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class munique_ptr
{
	T* _ptr;
private:
	munique_ptr(const T*) 	= delete;
	T* operator =(const T*);
public:
	munique_ptr();
	munique_ptr(T*);
	~munique_ptr();
public:
	T& operator*();
	T* operator->();
public:
	T* get();
};

template<typename T>
munique_ptr<T>::munique_ptr()
	:
	_ptr(nullptr) {}

template<typename T>
munique_ptr<T>::munique_ptr(T* ptr)
	:
	_ptr(ptr) {}

template<typename T>
munique_ptr<T>::~munique_ptr()
{
	delete _ptr;
}

template<typename T>
T& munique_ptr<T>::operator *()
{
	return *_ptr;
}

template<typename T>
T* munique_ptr<T>::operator->()
{
	return _ptr;
}

template<typename T>
T* munique_ptr<T>::get()
{
	return _ptr;
}


int main() {

	int f = 1;
	int s = 2;

	unique_ptr<int> uniq(&f);
	munique_ptr<int> muniq(&s);

	cout << *uniq << " : " << uniq.get() << endl;
	cout << *muniq << " : " << muniq.get() << endl;

	return 0;
}

