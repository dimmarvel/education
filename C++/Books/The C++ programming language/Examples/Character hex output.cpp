#include <iostream>
#include <string.h>
using namespace std;

char alpha[] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    int sz = strlen(alpha);
    for (int i = 0; i < sz; i++)
    {
        char ch = alpha[i];
        cout << '\'' << ch << '\'' << " = " << int(ch) << " = 0" << oct << int(ch) << " = 0x" << hex << int(ch) << '\n';
    }
    system("pause");
}