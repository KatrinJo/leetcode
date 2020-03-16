class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pos;
        int i, j;
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                if (matrix[i][j] == 0)
                    pos.push_back(vector<int>{i,j});
        for (auto & v : pos) {
            j = v[1];
            for (i = 0; i < n; ++i)
                matrix[i][j] = 0;
            i = v[0];
            for (j = 0; j < m; ++j)
                matrix[i][j] = 0;
        }
    }
};