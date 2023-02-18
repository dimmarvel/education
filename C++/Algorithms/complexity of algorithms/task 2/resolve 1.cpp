#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 2, 1, 2, 4};
    int ans = -1;
    int input;

    cin >> input;

    for (int i = 0; i < vec.size(); ++i)
        if (ans == -1 && vec[i] == input)
            ans = i;
    cout << ans << endl;

    return 0;
}
