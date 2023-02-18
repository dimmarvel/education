#include <iostream>

using namespace std;

void pswap(int* first, int* sec)
{
    int temp = *first;
    *first = *sec;
    *sec = temp;
}
void lswap(int& first, int& sec)
{
    int temp = first;
    first = sec;
    sec = temp;
}

int main()
{
    int f = 10, s = 20;
    cout << "f = " << f << ", "
         << "s = " << s << endl;
    pswap(&f, &s);
    cout << "pswap f = " << f << ", "
         << "s = " << s << endl;
    lswap(f, s);
    cout << "lswap f = " << f << ", "
         << "s = " << s << endl;
    system("pause");
}