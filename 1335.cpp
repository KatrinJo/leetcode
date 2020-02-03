// dp

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> maxDiff(n, vector<int>(n));
        vector<int> sumDiff(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            maxDiff[i][i] = jobDifficulty[i];
            sumDiff[i+1] = sumDiff[i] +jobDifficulty[i];
        }

        vector<vector<int>> myvec(n, vector<int>(d + 1,sumDiff[n]));
        myvec[0][1] = jobDifficulty[0];
        for (int dis = 1; dis < n; ++dis) {
            for (int i = 0; i < n - dis; ++i) {
                maxDiff[i][i + dis] = max(maxDiff[i][i+dis-1], jobDifficulty[i+dis]);
            }
            myvec[dis][1] =maxDiff[0][dis];
        }

        for (int k = 2; k <= d; ++k) {
            myvec[k-1][k] = sumDiff[k];
            for (int i = k; i < n; ++i) {
                for (int j = k - 2; j <= i - 1; ++j) {
                    myvec[i][k] = min(myvec[i][k], myvec[j][k-1]+maxDiff[j+1][i]);
                }
            }
        }
        return myvec[n-1][d];
    }
};
