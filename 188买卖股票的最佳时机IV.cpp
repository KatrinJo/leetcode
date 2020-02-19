// 这道题的转移方程有点复杂……

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int d = prices.size();
        if (d <= 1 || k < 1)
            return 0;
        if (k >= d/2)
            return maxProfit2(d, prices);
        vector<vector<int>> local(d,vector<int>(k+1,0)), global(d,vector<int>(k+1,0));
        vector<int> tmp;
        for (int i = 1; i < d; ++i)
            tmp.push_back(prices[i] - prices[i-1]);   

        for (int i = 1; i < d; ++i) {
            for (int j = 1; j <= k; ++j) {
                local[i][j] = max(global[i-1][j-1]+max(tmp[i-1],0), local[i-1][j]+tmp[i-1]);
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
       
        return global[d-1][k];
    }
    int maxProfit2(int n, vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            sum += max(0, prices[i] - prices[i-1]);
        }
        return sum;
    }
};