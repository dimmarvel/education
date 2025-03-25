class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int buy_p = prices[0];
        int profit;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(buy_p > prices[i])
                buy_p = prices[i];
            profit = max(profit, prices[i] - buy_p);
        }
        return profit;
    }
};