#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Some
{
public:
	int a;
	string data;
public:

	void get_data()
	{
		cout << a << endl;
		cout << data << endl;
	}
};

Some& SomeInstance()
{
	static Some* s = new Some();
	return *s;
}

int main()
{
	SomeInstance().a = 1;
	SomeInstance().data = "string";
	SomeInstance().get_data();
	return 0;
}
