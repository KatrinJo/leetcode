// 可能要考虑如果隔了k天……

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int with = -prices[0];
        int out[2] = {0,0};

        int tmp;
        for (int i = 1; i < n; ++i) {
            tmp = with;
            with = max(with, out[0]-prices[i]);
            out[0] = out[1];
            out[1] = max(out[1], tmp + prices[i]);
        }
        return out[1];
    }
};