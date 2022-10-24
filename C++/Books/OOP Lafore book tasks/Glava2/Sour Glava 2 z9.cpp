#include<iostream>
#include<iomanip>
using namespace std;

int main() {
 setlocale(LC_ALL, "Rus");

 int a,b,c,d;
 double a1, a2;
 char dummychar;

 cout << "¬ведите первую дробь: ";
 cin >> a >> dummychar >> b;

 
 cout << "¬ведите вторую дробь: ";
 cin >> c >> dummychar >> d;

 a1 = a*d+b*c; //числитель
 a2 = d*b; //знаменатель


 cout << "—умма равна " << a1 << "/" << a2;

 cout << endl;
 system("Pause");
}