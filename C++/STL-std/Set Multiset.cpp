#include <iostream>
#include <set> // binary tree
#include <vector>
using namespace std;

/*
            5
          /   \
         4     1
        / \   / \
       2   4 1   5

*/

int main()
{

    setlocale(LC_ALL, "Rus");

    //----------------------------

    set<int> mset;
    multiset<int> mmultiset;
    //уникальные значения, упорядочен всегда
    mmultiset.insert(1);
    mmultiset.insert(1);
    mmultiset.insert(1);
    mmultiset.insert(3);
    mmultiset.insert(5);
    cout << "Multiset: ";
    for (auto elem : mmultiset)
    {
        cout << elem << " ";
    }
    cout << endl;

    auto it1 = mmultiset.lower_bound(3); //вернет 3
    auto it2 = mmultiset.upper_bound(3); // вернет то что за 3
    cout << "lower_bound(3) - " << *it1 << endl;
    cout << "upper_bound(3) - " << *it2 << endl;

    auto it3 = mmultiset.equal_range(1);
    cout << "equal_range(1) - " << *it3.first << " " << *it3.second << endl;

    mset.insert(2);
    mset.insert(9);
    mset.insert(15);
    mset.insert(15);
    mset.insert(15);
    mset.insert(49);
    mset.insert(1);
    mset.insert(1);
    mset.insert(1);
    mset.insert(1);
    mset.insert(4);

    cout << "set: ";
    for (auto elem : mset)
    {
        cout << elem << " ";
    }

    auto it = mset.find(1);
    cout << "find 1 - " << *it << endl;

    if (mset.find(2) != mset.end())
    {
        cout << "numb " << 2 << " finded!" << endl;
    }
    else
    {
        cout << "numb not found";
    }

    system("Pause");
}