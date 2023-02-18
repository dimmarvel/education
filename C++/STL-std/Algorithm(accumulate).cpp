#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Person
{
public:
    Person(string name, double score)
    {
        this->name = name;
        this->score = score;
    }
    bool operator()(const Person& p) { return p.score > 100; }
    string name;
    double score;
};

int main()
{

    setlocale(LC_ALL, "Rus");
    vector<int> v = {1, 2, 4, 2, 3, 1, 7, 4};

    auto it = accumulate(v.begin(), v.end(), 0);
    auto it2 = accumulate(begin(v), end(v), 0);
    auto it3 = accumulate(begin(v), end(v), 1, [](int a, int b) { return a * b; });
    auto it4 = accumulate(begin(v), end(v), 1, [](int a, int b) { return (b % 2 == 0) ? a * b : a; });
    string it5 =
        accumulate(next(begin(v)), end(v), to_string(v[0]), [](string a, int b) { return a + "-" + to_string(b); });

    cout << "it(accum) - " << it << endl;
    cout << "it2(accum) - " << it2 << endl;
    cout << "it3(accum) - " << it3 << endl;
    cout << "it4(accum) - " << it4 << endl;
    cout << "it4(accum) - " << it5 << endl;

    system("Pause");
}