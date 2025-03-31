#include "p.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int left = 0;
        int right = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                res[i] = std::pow(nums[left],2);
                left++;
            }
            else
            {
                res[i] = std::pow(nums[right],2);
                right--;
            }
        }
        return res;
    }
};