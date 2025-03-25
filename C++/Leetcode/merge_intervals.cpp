#include "p.hpp"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(begin(intervals), end(intervals));
        std::vector<std::vector<int>> ans;
        std::pair<int, int> p;
        p = {intervals[0][0], intervals[0][1]};

        for(int i = 1; i < intervals.size(); ++i)
        {
            if(p.second > intervals[i][1]) continue;
            if(intervals[i][0] > p.second)
            {
                ans.push_back({p.first, p.second});
                p = {intervals[i][0], intervals[i][1]};
            } else
            {
                p.second = intervals[i][1];
            }
        }
        ans.push_back({p.first, p.second});
        return ans;
    }
};