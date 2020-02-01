// 打表+合理剪枝
// 不，是动归

class Solution {
public:
    int numSquares(int n) {
        if (n < 4)
            return n;
        vector<int> myvec(n + 1,0);
        myvec[1] = 1;
        myvec[2] = 2;
        myvec[3] = 3;
        int sqrtNum;
        int j = 2;
        for (int i = 4; i <= n; ++i) {
            if (j * j == i) {
                myvec[i] = 1;
                ++j;
            }
            else {
                myvec[i] = i;
                sqrtNum = sqrt(i);
                for (int k = 2; k <= sqrtNum;++k)
                    myvec[i] = min(myvec[i], myvec[k * k] + myvec[i - k * k]);
            }
        }
        return myvec[n];
    }
};
