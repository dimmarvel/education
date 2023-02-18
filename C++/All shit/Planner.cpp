#include <iostream>
#include <string>
#include <vector>

using namespace std;
int next_month(int current);

int main()
{
    int size;
    int currentmonth = 1;
    string command;

    vector<vector<vector<string>>> month = {
        vector<vector<string>>(NULL), vector<vector<string>>(32), vector<vector<string>>(29),
        vector<vector<string>>(32),   vector<vector<string>>(31), vector<vector<string>>(32),
        vector<vector<string>>(31),   vector<vector<string>>(32), vector<vector<string>>(32),
        vector<vector<string>>(31),   vector<vector<string>>(32), vector<vector<string>>(31),
        vector<vector<string>>(32),
    };

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> command;
        if (command == "ADD")
        {
            int day;
            string plan;

            cin >> day;
            cin >> plan;

            month[currentmonth][day].push_back(plan);
        }
        else if (command == "NEXT")
        {

            int currentMonth_daySize = month[currentmonth].size();
            int nextMonth_daySize = month[next_month(currentmonth)].size();

            currentMonth_daySize--; // 32-- size to 31 month day Yanvar
            nextMonth_daySize--;    // example 29 - size 29-- be 29 Febral

            for (int i = 1; i <= currentMonth_daySize; i++) // check plans in ALL days
            {
                if (month[currentmonth][i].size() > 0) // if this day have paln
                {

                    if (i > nextMonth_daySize) // if in this month more days then next month
                    {
                        while (currentMonth_daySize > nextMonth_daySize) // wrote this month in next month last day
                        {

                            for (int j = 0; j < month[currentmonth][currentMonth_daySize].size(); j++)
                            {
                                month[next_month(currentmonth)][nextMonth_daySize].push_back(
                                    month[currentmonth][currentMonth_daySize][j]);
                            }

                            if (month[currentmonth][currentMonth_daySize].size() != 0) // delete before month
                            {
                                month[currentmonth][currentMonth_daySize].clear();
                            }
                            currentMonth_daySize--;
                        }
                    }
                    else // if not more then just wrote in this day
                    {
                        for (int j = 0; j < month[currentmonth][i].size(); j++)
                        {
                            month[next_month(currentmonth)][i].push_back(month[currentmonth][i][j]);
                        }

                        if (month[currentmonth][i].size() != 0) // delete before month
                        {
                            month[currentmonth][i].clear();
                        }
                    }
                }
            }

            currentmonth = next_month(currentmonth);
        }
        else if (command == "DUMP")
        {
            int day_plan;
            cin >> day_plan;

            cout << month[currentmonth][day_plan].size() << " ";

            for (auto it : month[currentmonth][day_plan])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    system("pause");
}
/*
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
*/

int next_month(int current)
{
    if (current >= 12)
    {
        return 1;
    }
    else
    {
        return current + 1;
    }
}