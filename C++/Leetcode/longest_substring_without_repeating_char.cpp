#include "p.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> symbols;
        int max = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(symbols.find(s[i]) != symbols.end()){  
                if(max < symbols.size()) max = symbols.size();
                i = symbols[s[i]] + 1;
                symbols.clear();
            }
            symbols[s[i]] += i;
        }
        
        return max > symbols.size() ? max : symbols.size();
    }
};

int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str) << endl;
}