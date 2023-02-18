#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void Foo(int a) { cout << a; }

void DoSome(vector<int>& vc, function<void(int)> func)
{
    for (auto el : vc)
    {
        func(el);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    function<void(int)> f;
    vector<int> arr = {
        1, 2, 4, 5, 6, 1, 2, 4124, 12, 124, 52, 252, 5, 2, 1,
    };

    f = [](int a) { cout << "Anonim func - " << a << endl; };
    DoSome(arr, f);

    DoSome(arr, [](int a) { cout << "Anonim func - " << a << endl; });

    //---------------

    int p = 0;

    auto f1 = [&p]() { p = 5; };

    f1();

    //-----------------

    auto f31 = []() { return 1; };

    auto q = f31();

    system("pause");
}