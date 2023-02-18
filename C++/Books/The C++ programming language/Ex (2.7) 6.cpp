#include <iostream>

using namespace std;

int main()
{
    struct fudge
    {
        union
        {
            int i;
            int* p;
        };
    };
    fudge a;
    a.i = 4095;
    int* p = a.p;

    a.p = 0;
    cout << a.p << endl;
    system("pause");
}