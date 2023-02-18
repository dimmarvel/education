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

recursive_mutex rmtx;
/*
rmtx.lock();
rmtx.lock(); можно
rmtx.unlock();
rmtx.unlock();
*/
mutex mtx;
/*
mtx.lock();
mtx.lock(); нельзя
*/

void foo(int a)
{
    rmtx.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::microseconds(300));
    if (a <= 1)
    {
        cout << endl;
        rmtx.unlock();
        return;
    }
    a--;
    foo(a);
    rmtx.unlock();
}

int main()
{
    setlocale(LC_ALL, "rus");

    thread t1(foo, 10);
    thread t2(foo, 10);
    t1.join();
    t2.join();
    system("pause");
    return 0;
}