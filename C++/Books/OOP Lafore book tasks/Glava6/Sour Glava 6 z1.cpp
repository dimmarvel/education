#include<iostream>
using namespace std;
class Int {
private:
	int Integer;
public:
	Int(){
	Integer = 0;
	}
	Int(int ii) {
		Integer = ii;
	}
	void add(Int i2, Int i3) {
	Integer = i2.Integer + i3.Integer;
	}
	void show() {
		cout << Integer;
	}

};

int main() {
	setlocale(LC_ALL, "Rus");
	Int Int1(7);
	Int Int2(11);
	Int Int3;
	Int3.add(Int1,Int2);
	cout<< "\nInt3 = "; Int3.show();
	cout << endl;
	system("Pause");
}