#include<iostream>

using namespace std;

void f(char t); // temp varriable (normal)
void g(char& t); // normal
void h(const char& t); // bad

int main()
{
	f('a');
	g(49); // bad cuz we have no link on 49
	h(3300);
	return 0;
}
