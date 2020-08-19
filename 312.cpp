class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> res(n + 2, vector<int>(n + 2, 0));
        vector<int> val(n + 2, 1);
        for (int i = 1; i <= n; ++i)
            val[i] = nums[i - 1];
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    sum = val[i] * val[k] * val[j] + res[i][k] + res[k][j];
                    res[i][j] = max(sum, res[i][j]);
                }
            }
        }    
        return res[0][n + 1];
    }
};