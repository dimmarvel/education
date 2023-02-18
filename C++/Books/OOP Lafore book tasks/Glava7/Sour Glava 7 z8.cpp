#include <iostream>
using namespace std;

const int LIMIT = 100;

class Safearay
{
private:
    int array[LIMIT];

public:
    void putel(int n, int temp)
    {
        if (n < 0 || n > LIMIT - 1)
        {
            cout << "Warning! overflow array!" << endl;
            ;
            system("pause");
            exit(1);
        }
        array[n] = temp;
    }
    int getel(int n)
    {
        if (n < 0 || n > LIMIT - 1)
        {
            cout << "Warning! overflow array!" << endl;
            ;
            system("pause");
            exit(1);
        }
        return array[n];
    }
};
int main()
{
    Safearay sal;
    int temp = 12345;
    sal.putel(7, temp);
    temp = sal.getel(7);
    cout << temp << endl;
    system("pause");
    return 0;
}