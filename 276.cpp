class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        if (n == 0 || k == 0) return 0;
        if (k == 1) return n <= 2;
        vector<vector<int>> dp(2, vector<int>(n,0));
        dp[0][0] = 0; dp[1][0] = k;
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = dp[0][i - 1] * (k - 1) + dp[1][i - 1] * (k - 1);
        }
        return dp[0][n - 1] + dp[1][n - 1];
    }
};