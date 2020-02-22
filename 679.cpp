// 24点

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> myvec;
        for (int i = 0; i < 4; ++i)
            myvec.push_back(nums[i]);
        return check(myvec, 4);
    }

    bool check(vector<double> myvec, int n) {
        if (n == 1) {
            if (abs(myvec[0] - 24.0) < 1e-6)
                return true;
            return false;
        }
        int i, j;
        double numberi, numberj;
        for (i = 1; i < n; ++i) {
            numberi = myvec[i];
            for (j = 0; j < i; ++j) {
                numberj = myvec[j];
                myvec[i] = myvec[n - 1];

                myvec[j] = numberi + numberj;   
                if (check(myvec, n - 1)) return true;

                myvec[j] = numberi * numberj;              
                if (check(myvec, n - 1)) return true;

                if (numberj != 0) {
                    myvec[j] = numberi / numberj;              
                    if (check(myvec, n - 1)) return true;
                }

                if (numberi != 0) {
                    myvec[j] = numberj / numberi;              
                    if (check(myvec, n - 1)) return true;
                }

                myvec[j] = numberi - numberj;              
                if (check(myvec, n - 1)) return true;

                myvec[j] = numberj - numberi;              
                if (check(myvec, n - 1)) return true;

                myvec[j] = numberj;
            }
            myvec[i] = numberi;
        }
        return false;
    }
};