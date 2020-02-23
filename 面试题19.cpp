class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
		if (n == 0 && m == 0) return true;
		if (m == 0) return false;
		if (n == 0) {
			if (m == 1) return false;
			for (int i = 0; i < m; ++i) {
				if (p[i] != '*') {
					if (i == m - 1) return false;
					if (p[i + 1] != '*') return false;
				}
			}
			return true;
		}
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
		dp[0][0] = true;
		int i, j, t;
		for (j = 0; j < m; ++j) {
			if (p[j] != '*')
				dp[0][j + 1] = false;
			else
				dp[0][j + 1] = dp[0][j - 1];
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (s[i] == p[j] || p[j] == '.') {
					dp[i + 1][j + 1] = dp[i][j];
				}
				else if (p[j] == '*' && j >= 1) {
					if (p[j - 1] == '.') {
                        // dp[i + 1][j - 1] .不用
                        // dp[i + 1][j] .只用一次
                        // dp[i][j + 1] . 用好多次（累积到dp了）
						dp[i + 1][j + 1] = dp[i + 1][j] || dp[i + 1][j - 1] || dp[i][j + 1];
					}
					else {
						if (p[j - 1] != s[i]) {
							dp[i + 1][j + 1] = dp[i + 1][j - 1];
                        }
						else {
                            // dp[i][j + 1] s里更多s[i]
                            // dp[i + 1][j - 1] p里更多s[i] 由于是s[i]*连用 消去
							dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j - 1];
                        }
					}
				}
			}
		}
		return dp[n][m];
	}
};