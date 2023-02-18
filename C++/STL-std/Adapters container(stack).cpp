#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");

    stack<int, vector<int>> st;

    st.push(2);
    st.push(32);
    st.push(4);
    st.push(102);

    st.emplace(10);

    cout << "size = " << st.size() << endl;

    st.pop();

    cout << "top - " << st.top() << endl;

    auto a = st._Get_container();

    cout << "a[0] - " << a[0] << endl;

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    system("Pause");
}