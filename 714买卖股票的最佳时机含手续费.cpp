// 和II的第一个解法有点点像

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int d = prices.size();
        if (d <= 1)
            return 0;
        int with = -prices[0]-fee, without = 0;
        int tmp;
        for (int i = 1; i < d; ++i) {
            tmp = with;
            with = max(with, without - prices[i] - fee);
            without = max(without, tmp + prices[i]);
        }
        return without;
    }
};