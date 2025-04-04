#include "p.hpp"


class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;
        for(int i = 0; i < apple.size(); ++i)
            apples += apple[i];
        
        std::sort(capacity.begin(), capacity.end());
        int amount_tries = 0;
        int cap = 0;
        for(int i = capacity.size()-1; i >= 0; --i)
        {
            cap += capacity[i];
            ++amount_tries;
            if(cap > apples)
                return amount_tries;
        }
        return -1;
    }
};


int main()
{
    Solution s;
    std::vector<int> prices = {5,5,5};
    std::vector<int> cap = {2,4,2,7};
    cout << s.minimumBoxes(prices, cap) << endl;
}