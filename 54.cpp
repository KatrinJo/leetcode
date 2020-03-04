class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> visted(m, vector<bool>(n, false));
        int dir[5] = {0, 1, 0, -1, 0};
        int k = 0;
        int x = 0, y = -1, nx, ny, rest = m * n;
        while(rest > 0) {
            nx = x + dir[k];
            ny = y + dir[k + 1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                k = (k + 1) % 4;
                continue;
            }
            if (visted[nx][ny]) {
                k = (k + 1) % 4;
                continue;
            }
            visted[nx][ny] = true;
            res.push_back(matrix[nx][ny]);
            x = nx; y = ny;
            --rest;
        }
        return res;
    }
};