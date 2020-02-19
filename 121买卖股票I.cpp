// 简单打表
// summary: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) 
            return 0;
        int minv = prices[0], maxv = 0;
        for (auto & x : prices) {
            if (x > minv)
                maxv = max(maxv, x - minv);
            else
                minv = x; 
        }
        return maxv;
    }
};