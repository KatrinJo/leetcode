// 第K个最小的素数分数，是真的难顶……
// 对二分法不很熟……

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0.0, r = 1.0, med = 0.5;
        int p = 0, q = 1, cnt = 0, n = A.size();
     
        while(true) {
            med = (l + r) / 2.0;
            p = 0;
            cnt = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while(j < n && A[i] > med * A[j])
                    ++j;
                cnt += (n - j);
                if (j < n && A[i] * q > A[j] * p) {
                    p = A[i];
                    q = A[j];
                }
            }
            if (cnt == K)
                break;
            if (cnt < K) 
                l = med;
            if (cnt > K)
                r = med;
        }
        
        return vector<int>{p,q};
    }
};