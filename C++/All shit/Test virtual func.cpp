#include <iostream>
using namespace std;
int sum(int&, int);

void main()
{
    int n, k;
    n = 1;
    cout << "Inpur num K";
    cin >> k;
    for (bool tr = false, int i = 1; tr == false; i++)
    {
        cout << "i = " << i << endl;
        if (sum(n, k) == k)
        {
            cout << "I FIND = " << n << endl;
            tr = true;
        }
    }
    system("pause");
};

int sum(int& numb, int cycle)
{
    for (; numb < cycle;)
    {
        numb = numb++;
    }
    return numb;
}