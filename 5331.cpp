// dp

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        if (n <= 2)
            return n;
        vector<vector<int>> myarr;
        for (int i = 0; i < n; ++i)
            myarr.push_back(vector<int>{arr[i], i});
        sort(myarr.begin(), myarr.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] < b[0];
        });

        vector<int> dp(n, 1);
        int idx = 0, height = 0, j;
        for (int i = 0; i < n; ++i) {
            height = myarr[i][0];
            idx = myarr[i][1];

            for (j = 1; j <= d; ++j) {
                if (j + idx >= n)
                    break;
                if (height <= arr[j + idx])
                    break;
                dp[idx] = max(dp[idx], dp[j + idx] + 1);
            }
            for (j = 1; j <= d; ++j) {
                if (idx - j < 0)
                    break;
                if (height <= arr[idx - j])
                    break;
                dp[idx] = max(dp[idx], dp[idx - j] + 1);
            }
        }   

        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dp[i]);

        return res;
    }
};
