#include "p.hpp"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max = 0;
        while(j > i)
        {
            int p = min(height[i], height[j]) * (j - i);
            if(p > max)
            {
                max = p;
            }
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return max;  
    }
};