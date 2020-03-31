class Solution {
public:
    int minDistance(string word1, string word2) {
        int slen1 = word1.length(), slen2 = word2.length();
        if (slen1 == 0)
            return slen2;
        if (slen2 == 0)
            return slen1;
        vector<vector<int>> dp(slen1 + 1, vector<int>(slen2 + 1, 0));
        for (int i = 1; i <= slen2; ++i)
            dp[0][i] = i;
        for (int i = 1; i <= slen1; ++i)
            dp[i][0] = i;
        for (int i = 1; i <= slen1; ++i)
            for (int j = 1; j <= slen2; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
                dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j - 1]) + 1);
            }
        return dp[slen1][slen2];
    }
};