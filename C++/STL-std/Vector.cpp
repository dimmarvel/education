#include <iostream>
#include <vector>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");

    //----------------------------

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(10);
    arr.push_back(100);
    arr.push_back(1000);
    arr.push_back(10000);
    arr.push_back(100000);
    arr.push_back(1000000);
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();

    cout << "All elements: " << arr.size() << endl << "Elements: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    // arr[5]; //not checked range of array ERROR
    arr.at(1); // checked range of array

    try
    {
        cout << arr.at(10) << endl;
    }
    catch (const out_of_range& ex)
    {
        cout << endl << ex.what() << endl << endl;
    }

    arr.clear();
    cout << "clear - size = " << arr.size() << endl;

    cout << "----------------------------------------" << endl;

    //------------------------------------------------------------------------------------------

    vector<int> arr2(20, 55);

    arr2.reserve(100000); // change capasity чтобы не перевыделять memory

    cout << "capacity - " << arr2.capacity()
         << endl; // new memory create with запасом, т.е. capacity показывает под сколько элемов выделено memort
    cout << "size - " << arr2.size() << endl;

    arr2.shrink_to_fit(); //выровнять capasity под кол-во элементов

    cout << "capacity - " << arr2.capacity()
         << endl; // new memory create with запасом, т.е. capacity показывает под сколько элемов выделено memort
    cout << "size - " << arr2.size() << endl;
    cout << "empty - " << arr2.empty() << endl;

    arr2.resize(15);

    cout << "resize - size - " << arr2.size() << endl;

    //----------------------------
    system("Pause");
}