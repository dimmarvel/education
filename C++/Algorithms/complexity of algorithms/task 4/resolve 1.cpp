#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1,2,3,2,1,2,4};
    int ans = vec[0];

    for (int i = 1; i < vec.size(); ++i)
        if(vec[i] > ans)
            ans = vec[i];

    cout << ans << endl;

    return 0;
}
