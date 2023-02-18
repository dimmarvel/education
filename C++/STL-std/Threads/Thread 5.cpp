#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void addfunc(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "----------THREAD ADDFUNC START-----------" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "Sum a + b = " << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "----------THREAD ADDFUNC END-----------" << endl;
}

int main()
{

    thread th(addfunc, 2, 3);

    for (int i = 0; true; i++)
    {
        cout << "ID - " << this_thread::get_id() << "\t MAIN IS WORK\t - " << i << endl;

        this_thread::sleep_for(chrono::milliseconds(800));

        // if ((i % 5) == 0)
        //	addfunc(2, 5);
    }
    th.join();
    system("pause");
    return 0;
}