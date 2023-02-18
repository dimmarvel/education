#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    char ch, zn;
    do
    {
        cout << "Vvedite 1-y drob" << endl;
        cin >> a >> ch >> b;
        cout << "Vvedite znak" << endl;
        cin >> zn;
        cout << "Vvedite 2-y drob" << endl;
        cin >> c >> ch >> d;
        switch (zn)
        {
        case '+':
            e = a * d + b * c;
            f = b * d;
            break;
        case '-':
            e = a * d - b * c;
            f = b * d;
            break;
        case '*':
            e = a * c;
            f = b * d;
            break;
        case '/':
            e = a * d;
            f = b * c;
            break;
        }
        cout << e << ch << f << endl;
        cout << "esche raz? (y,n)" << endl;
        cin >> ch;
    } while (ch != 'n');
    return 0;
}