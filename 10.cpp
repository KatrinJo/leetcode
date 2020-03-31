class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
        
        dp[0][0] = true;
        for (int j = 1; j <= plen; ++j)
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        
        for (int i = 1; i <= slen; ++i)
            for (int j = 1; j <= plen; ++j) {
                if (p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] >= 'a' && p[j - 1] <= 'z') {
                    if (s[i - 1] == p[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    if (p[j - 2] == '.' || (p[j - 2] >= 'a' && p[j - 2] <= 'z' && s[i - 1] == p[j - 2])) {
                        dp[i][j] = dp[i - 1][j - 2] || dp[i][j - 2] || dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        return dp[slen][plen];
    }
};