// 说实话我超级虚……dp题目不太敢肯定……

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> myvec;
        vector<int> dp(n + 1, 0), num(n + 1, n + 2);
        for (int i = 0; i <= n; ++i) {
            myvec.push_back(vector<int> {i - ranges[i], i + ranges[i]});
        }
        sort(myvec.begin(), myvec.end(), [](const vector<int> & a, const vector<int> & b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int i;
        for (i = 0; i <= n; ++i) {
            if (myvec[i][0] <= 0) {
                dp[i] = myvec[i][1];
                num[i] = 1;
            }
            else {
                break;
            }
        }
        bool flag = false;
        for (; i <= n; ++i) {
            flag = false;
            for (int j = i - 1; j>= 0; --j) {
                if (myvec[i][0] <= myvec[j][1]) {
                    dp[i] = max(dp[i], myvec[i][1]);
                    num[i] = min(num[i], num[j] + 1);
                    flag = true;
                }
            }
            if (!flag) {
                return -1;
            }
        }
        int minnum = n + 2;
        for (i = 0; i <= n; ++i) {
            if (dp[i] >= n) {
                minnum = min(minnum, num[i]);
            }
        }
        return minnum;
    }
};
