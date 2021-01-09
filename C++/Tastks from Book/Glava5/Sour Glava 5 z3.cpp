//функция возводит число в степень
#include <iostream>
using namespace std;
void zeroSmaller(int&, int&);//p has default value 2

int main()
{
	setlocale(LC_ALL,"Rus");
	int one, two;
	cout << "input first number and secodn, who will be smaller him value equally 0: " << endl;
	cin >> one >> two;
	
	zeroSmaller(one, two);

	cout << "First  = " << one <<  endl;
	cout << "Second = " << two <<  endl;
	
	system("pause");
}

void zeroSmaller(int& one, int& two)
{
	if (one < two) {
		one = 0;
	}
	else {
		two = 0;
	}

}


