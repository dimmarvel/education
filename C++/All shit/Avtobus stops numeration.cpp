#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void push_one(vector<string>& vec, string name)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == name)
        {
            return;
        }
    }
    vec.push_back(name);
}

int main()
{
    map<string, vector<string>> bus;
    vector<string> stack;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string command;
        cin >> command;

        if (command == "NEW_BUS")
        {
            int stop_count;
            string ostanovka;
            string bus_name;

            cin >> bus_name >> stop_count;

            for (int i = 0; i < stop_count; i++)
            {
                cin >> ostanovka;
                bus[bus_name].push_back(ostanovka);
                push_one(stack, bus_name);
            }
        }
        else if (command == "BUSES_FOR_STOP")
        {
            string ostanovka;
            vector<string> busses_ostanovka;

            cin >> ostanovka;

            if (!bus.empty())
            {

                for (const auto& it_bus : bus)
                {
                    for (const auto it_ost : it_bus.second)
                    {
                        if (it_ost == ostanovka)
                        {
                            busses_ostanovka.push_back(it_bus.first);
                            break;
                        }
                    }
                }

                if (!busses_ostanovka.empty())
                {
                    for (int i = 0; i < stack.size(); i++)
                    {
                        for (const auto& it : busses_ostanovka)
                        {
                            string stack_elem = stack[i];

                            if (stack_elem == it)
                            {
                                cout << it << " ";
                            }
                        }
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No stop" << endl;
                }

                /*if (!busses_ostanovka.empty()) {
                    for (const auto& it : busses_ostanovka)
                    {
                        cout << it << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No stop" << endl;
                }*/
            }
            else
            {
                cout << "No stop" << endl;
            }
        }
        else if (command == "STOPS_FOR_BUS")
        {
            string bus_name;
            cin >> bus_name;

            auto find_bus = bus.find(bus_name);

            if (find_bus != bus.end())
            {
                for (const auto& it_stop : bus[bus_name])
                {
                    vector<string> stops;
                    cout << "Stop " << it_stop << ": ";
                    for (const auto& it_another_bus : bus)
                    {
                        bool is_empty = true;
                        for (const auto& it_another_stop : it_another_bus.second)
                        {
                            if (bus_name == it_another_bus.first)
                            {
                                continue;
                            }

                            if (it_another_stop == it_stop)
                            {
                                stops.push_back(it_another_bus.first);
                                break;
                            }
                        }
                    }

                    if (!stops.empty())
                    {
                        for (int i = 0; i < stack.size(); i++)
                        {
                            for (const auto& it : stops)
                            {
                                string stack_elem = stack[i];

                                if (stack_elem == it)
                                {
                                    cout << it << " ";
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "no interchange";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "No bus" << endl;
            }
        }
        else if (command == "ALL_BUSES")
        {
            if (!bus.empty())
            {
                for (const auto& it_bus : bus)
                {
                    cout << "Bus " << it_bus.first << ": ";
                    for (const auto& it_stops : it_bus.second)
                    {
                        cout << it_stops << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "No buses" << endl;
            }
        }
    }
}