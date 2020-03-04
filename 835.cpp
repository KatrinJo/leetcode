class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        if (n == 0) return 0;
        int res = 0, tmp, sum;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 向左、右移动i
                // 向上、下移动j
                // A: (i, j)->(n-1,n-1)    B:(0,0)->(n - 1 - i,n - 1 - j)
                // A: (i, 0)->(n-1,n-1-j)  B:(0,j)->(n-1-i, n-1)
                // A: (0, j)->(n-1-i,n-1)  B:(i,0)->(n-1,n-1-j)
                // A: (0, 0)->(n-1-i,n-1-j)B:(i,j)->(n-1,n-1)
                
                vector<vector<int>> s{{i,j},{i,0},{0,j},{0,0}};
                vector<vector<int>> d{{-i,-j},{-i,j},{i,-j},{i,j}};
                sum = (n - i) * (n - j);
                for (int k = 0; k < 4; ++k) {
                    if (res >= sum) break;
                    tmp = 0;
                    for (int ai = s[k][0]; ai <= n-1-i+s[k][0]; ++ai) {
                        for (int aj = s[k][1]; aj <= n-1-j+s[k][1]; ++aj) {
                            if (A[ai][aj] == 0) continue;
                            if (A[ai][aj] == B[ai+d[k][0]][aj+d[k][1]])
                                ++tmp;
                        }
                    }
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};