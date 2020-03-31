class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1)
            return 0;
        int slen = s.length();
        vector<int> dp(slen, 0);
        for (int i = 1; i < slen; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                else {
                    if (i <= dp[i - 1])
                        dp[i] = 0;
                    else if (s[i - 1 - dp[i - 1]] == '(') {
                        dp[i] = i >= 2 + dp[i - 1] ? dp[i - 2 - dp[i - 1]] + dp[i - 1] + 2 : dp[i - 1] + 2;
                    }
                }
            }
        }
        int maxv = 0;
        for (int i = 1; i < slen; ++i) {
            maxv = max(maxv, dp[i]);
        }
        return maxv;
    }
};