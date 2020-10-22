
#include <iostream>
using namespace std;

int main() {
	char str[] = "a short string";
	cout << sizeof(str)-1 << endl; //-1 == '\0'
	return 0;
}
