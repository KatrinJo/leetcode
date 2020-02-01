// dfs+打表。是大一的题目……但是现在还是忘记怎么做了（允悲）。

class Solution {
public:
    int dfs(vector<vector<int>>& res, vector<vector<int>>& matrix, vector<vector<bool>>& visted, int m, int n, int x, int y) {
        if (visted[x][y]) {
            return res[x][y];
        }
        int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        int nx, ny;
        for (int k = 0; k < 4; ++k) {
            nx = x + d[k][0];
            ny = y + d[k][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (matrix[x][y] > matrix[nx][ny]) {
                if (visted[nx][ny]) {
                    res[x][y] = max(res[x][y], res[nx][ny] + 1);
                }
                else {
                    res[nx][ny] = dfs(res, matrix, visted, m, n, nx, ny);
                    res[x][y] = max(res[x][y], res[nx][ny] + 1);
                }
            }
        } 
        visted[x][y] = true;
        return res[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> f(m, vector<int>(n,1));
        vector<vector<bool>> visted(m, vector<bool>(n,false));
        // stack<pair<int, int>> dfsstack;
        int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        int res = 1, tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visted[i][j])
                    continue;
                // dfsstack.push(make_pair<i,j>);
                tmp = dfs(f, matrix, visted, m, n, i, j);
                res = max(res, tmp);
            }
        }

        return res;
    }
};
