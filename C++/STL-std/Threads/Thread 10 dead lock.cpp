#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
class Tim
{
private:
    chrono::time_point<chrono::steady_clock> start, end;
    chrono::duration<float> duration;

public:
    void mTimer() { start = chrono::high_resolution_clock::now(); }
    ~Tim()
    {
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        float result = duration.count();
        cout << "Proshlo time - " << result << endl;
    }
};

mutex mtx;
mutex mtx2;
void Print(char ch)
{
    mtx.lock();
    this_thread::sleep_for(chrono::milliseconds(10)); // deadlock избегаем совместного использования mtx && mtx2
    mtx2.lock();

    {
        lock_guard<mutex> guard(mtx);
        for (int i = 0; i < 5; i++)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout << endl;
        }
    }

    mtx.unlock();
    mtx2.unlock();
}
void Print2(char ch)
{
    mtx.lock();
    this_thread::sleep_for(chrono::milliseconds(1000)); // dead lock
    mtx2.lock();

    {
        lock_guard<mutex> guard(mtx);
        for (int i = 0; i < 5; i++)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout << endl;
        }
    }

    mtx.unlock();
    mtx2.unlock();
}

int main()
{
    setlocale(LC_ALL, "rus");

    Tim qw;

    thread t1(Print, '#');
    thread t2(Print2, '*');
    t1.join();
    t2.join();

    qw.~Tim();
    system("pause");
    return 0;
}