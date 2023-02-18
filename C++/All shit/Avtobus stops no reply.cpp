#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// справочник стран\столиц

int main()
{
    map<int, set<string>> bus;
    int size;
    int counter = 0;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int how;
        set<string> stops;
        string stop;

        cin >> how;

        for (int i = 0; i < how; i++)
        {
            cin >> stop;
            stops.insert(stop);
        }

        bool is_here = false;
        for (const auto& it : bus)
        {

            if (it.second == stops)
            {
                is_here = true;
                cout << "Already exists for " << it.first << endl;
                break;
            }
        }

        if (!is_here)
        {
            bus[++counter] = stops;
            cout << "New bus " << counter << endl;
        }
    }
}