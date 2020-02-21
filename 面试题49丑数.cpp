// Solution 1 

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long int> dp{1,2,3};
        if (n <= 3)
            return dp[n-1];
        long long int last = 3, nextv;
        for (int i = 3; i < n; ++i) {
            nextv = last * 2;
            for (int j = 0; j < i; ++j) {
                if (dp[j] * 2 > last) 
                    nextv = min(nextv, dp[j] * 2);
                else if (dp[j] * 3 > last) 
                    nextv = min(nextv, dp[j] * 3);
                else if (dp[j] * 5 > last) 
                    nextv = min(nextv, dp[j] * 5);
            }
            dp.push_back(nextv);
            last = nextv;
        }
        return dp[n-1];
    }
};


// Solution 2 快很多，但是不太理解……
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long int> dp(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            // 移动指针
            if (dp[i] == dp[p2] * 2) ++p2;
            if (dp[i] == dp[p3] * 3) ++p3;
            if (dp[i] == dp[p5] * 5) ++p5;
        }
        return dp[n - 1];
    }
};