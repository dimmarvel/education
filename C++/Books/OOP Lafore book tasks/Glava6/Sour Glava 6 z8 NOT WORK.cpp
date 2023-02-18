#include <iostream>
using namespace std;

class statobj
{
private:
    int count;

public:
    statobj() { count++; }
    int showinfo() { return count; }
};

// int statobj::count = 0;

int main()
{
    // setlocale(LC_ALL, "Rus");
    statobj o1, o2, o3;
    cout << o1.showinfo() << endl;
    cout << o2.showinfo() << endl;
    cout << o3.showinfo() << endl;
    cout << endl;
    system("Pause");
}