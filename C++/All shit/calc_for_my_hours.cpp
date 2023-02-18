#include <iostream>
using namespace std;

void calc(float& sum, float& plus, int& counter)
{
    while (true)
    {
        cin >> plus;
        if (plus >= 0)
        {
            int p = plus;
            counter++;
            float after_point = plus - p;
            /*while (after_point >= 0.6) {
                plus -= 0.6;
                plus += 1;
                p = plus;
                cout << "plus = " << plus << endl;
                after_point = plus - p;
                cout << "after_point = " << after_point << endl;
            }*/

            sum += plus;

            p = sum;
            after_point = sum - p;
            while (after_point >= 0.5889)
            {
                sum -= 0.6;
                sum += 1;
                p = sum;
                after_point = sum - p;
            }
            cout << "Sum = " << sum << " hours per day" << endl;
        }
        else
        {
            cout << "\naverage = " << sum / counter << " hours for " << counter << " days.\n";
        }
    }
}

int main()
{

    float sum = 0;
    float plus = 0;
    int counter = 0;

    calc(sum, plus, counter);
    float s = sum / counter;
    cout << "\naverage = " << s << " hours for " << counter << " days.\n";

    system("pause");
}