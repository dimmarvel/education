#include <forward_list>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void PrintList(forward_list<T>& flst)
{
    for (auto i : flst)
        cout << i << " ";
    cout << endl;
}

int main()
{

    setlocale(LC_ALL, "Rus");

    forward_list<int> flst;

    flst.push_front(10);
    flst.push_front(9);
    flst.push_front(9);
    flst.push_front(3);
    flst.push_front(8);

    forward_list<int>::iterator it = flst.begin();

    PrintList(flst);
    cout << "Insert_after(it,9999): ";
    it++;

    flst.insert_after(it, 9999);
    PrintList(flst);
    cout << "IT - " << *it << endl;

    // it--; //ERROR потому что мы не храним адрес предыдущего
    // lst[1]; ERROR

    system("Pause");
}