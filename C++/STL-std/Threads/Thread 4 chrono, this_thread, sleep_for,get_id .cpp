#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void DOsmth()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "ID - " << this_thread::get_id() << "\t DOsmth  - " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{

    thread th(DOsmth);

    for (int i = 0; i < 10; i++)
    {
        cout << "ID - " << this_thread::get_id() << "\t MAIN - " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();
    system("pause");
    return 0;
}