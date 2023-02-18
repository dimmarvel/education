#include <iostream>
#include <vector>

using namespace std;

bool min(int first, int second) { return (first < second) ? first : second; }

bool max(int first, int second) { return (first > second) ? first : second; }

int main()
{
    vector<int> vec = {1, 2, 3, 2, 1, 2, 4};
    int ans1_max = max(vec[0], vec[1]);
    int ans2_max = min(vec[0], vec[1]);

    for (int i = 1; i < vec.size(); ++i)
        if (vec[i] > ans2_max)
        {
            ans2_max = ans1_max;
            ans1_max = vec[i];
        }
        else if (vec[i] > ans2_max)
        {
            ans2_max = vec[i];
        }

    cout << "max1 = " << ans1_max << " --- max2 = " << ans2_max << endl;

    return 0;
}
