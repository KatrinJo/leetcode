// 分两段，各自按照121买卖股票I做

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) 
            return 0;
        vector<int> bef(n, 0), aft(n, 0);
        int minv = prices[0], maxv = 0;
        for (int i = 0; i < n; ++i) {
            if (prices[i] > minv)
                maxv = max(maxv, prices[i] - minv);
            else
                minv = prices[i]; 
            bef[i] = maxv;
        }
        minv = 0, maxv = prices[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            if (prices[i] < maxv)
                minv = max(minv, maxv - prices[i]);
            else
                maxv = prices[i]; 
            aft[i] = minv;
        }
        maxv = 0;
        for (int i = 0; i < n; ++i) {
            maxv = max(maxv, bef[i] + aft[i]);
        }
        return maxv;
    }
};