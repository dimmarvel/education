#include <iostream>

using namespace std;

int main()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << (char)i << " - " << i << " - 0x" << hex << i << endl;
    }
    for (int i = '0'; i <= '9'; i++)
    {
        cout << (char)i << " - " << i << " - 0x" << hex << i << endl;
    }
    system("pause");
}