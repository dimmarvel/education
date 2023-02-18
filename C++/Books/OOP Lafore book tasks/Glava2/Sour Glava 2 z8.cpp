#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    char a = '.';

    cout << "Moscow" << setfill(a) << setw(10) << 12241 << endl;

    system("pause");
}