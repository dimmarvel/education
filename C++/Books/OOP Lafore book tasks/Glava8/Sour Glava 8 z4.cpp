#include <iostream>
#include <process.h>
using namespace std;
class Int
{
private:
    int Integer;

public:
    Int() { Integer = 0; }
    Int(int ii) { Integer = ii; }
    Int operator+(Int i) { return checkit(long double(Integer) + long double(i.Integer)); }
    Int operator-(Int i) { return checkit(long double(Integer) - long double(i.Integer)); }
    Int operator*(Int i) { return checkit(long double(Integer) * long double(i.Integer)); }
    Int operator/(Int i) { return checkit(long double(Integer) / long double(i.Integer)); }
    void show() { cout << Integer; }
    void getint() { cin >> Integer; }
    Int checkit(long double answer)
    {
        if (answer > 2147483647.0L || answer < -2147483647)
        {
            cout << "\nError";
        }
        else
        {
            return Int(int(answer));
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    Int alpha = 20;
    Int beta = 5;
    Int gamma, delta;
    gamma = alpha + beta;
    cout << "\n1 = ";
    gamma.show();

    gamma = alpha - beta;
    cout << "\n2 = ";
    gamma.show();

    gamma = alpha * beta;
    cout << "\n3 = ";
    gamma.show();

    gamma = alpha / beta;
    cout << "\n4 = ";
    gamma.show();
    delta = 2147483647;
    gamma = delta + alpha;
    delta = -2147483647;
    gamma = delta - alpha;
    cout << endl;
    system("Pause");
}