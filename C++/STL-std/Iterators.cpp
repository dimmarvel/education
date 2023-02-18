#include <iostream>
#include <vector>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");
    //-------------------------

    vector<int> arr = {1, 204, 555, 2, 42, 5, 6, 26, 7, 2};

    auto it = arr.begin();
    // vector<int>::iterator it;

    cout << "it = " << *it << endl;

    *it = 11111;

    cout << "it = " << *it << endl;

    advance(it, 3);
    cout << "advance(it,3) - " << *it << endl;

    cout << "++it = " << *(++it) << endl;

    cout << endl << "______________________________________________" << endl;
    //--------------------------------------------------------------------------------------------------

    vector<int> arr2 = {1, 204, 555, 2, 42, 5, 6, 26, 7, 2};

    vector<int>::iterator itErase = arr2.begin();
    // auto itErase = arr2.begin();

    cout << "erase(5 elem delete) " << endl;

    for (vector<int>::iterator iter = arr2.begin(); iter != arr2.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    advance(itErase, 5);
    arr2.erase(itErase);

    cout << "erase(5 elem delete) " << endl;
    for (vector<int>::iterator iter = arr2.begin(); iter != arr2.end(); iter++)
        cout << *iter << " ";

    cout << endl << "______________________________________________" << endl;
    //--------------------------------------------------------------------------------------------------

    cout << "\nJustIT: ";
    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        cout << *iter << " ";
    }

    cout << "\nConstIT: ";
    for (vector<int>::const_iterator iter = arr.cbegin(); iter != arr.cend(); iter++) // unchangeble
    {
        cout << *iter << " ";
    }

    cout << "\nReverseIT: ";
    for (vector<int>::reverse_iterator iter = arr.rbegin(); iter != arr.rend();
         iter++) // rbegin - reverse begin, rend - reverse end
    {
        cout << *iter << " ";
    }
    cout << endl;

    system("Pause");
}