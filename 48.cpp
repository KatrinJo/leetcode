class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return;
        int n = matrix.size();
        int tmp;
        for (int i = 0; i <= (n-1)/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                tmp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};