#include "p.hpp"

class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_map<char, int> ch_pos;
        for(int i = 0; i < s.size(); ++i)
        {
            ch_pos[s[i]] = i;
        }

        vector<int> res;
        int start = 0, end = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            end = max(end, ch_pos[s[i]]);
            if(i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};