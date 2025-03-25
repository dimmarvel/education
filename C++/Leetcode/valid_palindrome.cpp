#include "p.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::erase_if(s, [](unsigned char c){return !isalnum(c);} );
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str = "0P";
    cout << s.isPalindrome(str) << endl;
}