#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int addfunc(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "----------THREAD ADDFUNC START-----------" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "----------THREAD ADDFUNC END-----------" << endl;
    return a + b;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int result;
    thread th([&result]() { result = addfunc(2, 100); });

    cout << endl << result << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << "ID - " << this_thread::get_id() << "\t MAIN IS WORK\t - " << i << endl;

        this_thread::sleep_for(chrono::milliseconds(800));

        // if ((i % 5) == 0)
        //	addfunc(2, 5);
    }
    cout << endl << result << endl;
    th.join();
    cout << endl << result << endl;
    system("pause");
    return 0;
}