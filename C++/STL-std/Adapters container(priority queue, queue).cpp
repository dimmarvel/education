#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");

    queue<int, list<int>> ql;
    queue<int, deque<int>> qd;
    queue<int, vector<int>> qv;
    queue<int, stack<int>> qs;

    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(10);
    pq.push(4);
    pq.push(9);

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
        cout << "size - " << pq.size() << endl;
    }

    system("Pause");
}