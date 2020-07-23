class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        int x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                x = max(0, i - 1);
                y = max(0, j - 1);
                dp[i][j] = min(dp[x][j], dp[i][y]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};