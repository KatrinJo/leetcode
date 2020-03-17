class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, INT_MAX);
        res[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto & c : coins) {
                if (i < c) continue;
                if (res[i - c] < INT_MAX) 
                    res[i] = min(res[i - c] + 1, res[i]);
            }
        }
        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};