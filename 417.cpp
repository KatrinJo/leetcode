// bfs

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        if (m == 0) {
            return res;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return res;
        }

        int d[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        vector<int> visted(m*n, 0), visted2(m*n, 0);
        vector<int> myque;
        int vs = 0, ve = 0, x = 0, y = 0, nx, ny, tmp;
        for (int i = 0; i < m; ++i) {
            visted[i * n] = true;
            myque.push_back(i * n);
        }
        for (int j = 1; j < n; ++j) {
            visted[j] = true;
            myque.push_back(j);
        }
        vs = 0, ve = m + n - 1;

        while(vs < ve) {
            x = myque[vs] / n;
            y = myque[vs++] - x * n;

            for (int i = 0; i < 4; ++i) {
                nx = x + d[i][0];
                ny = y + d[i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (visted[nx * n + ny])
                    continue;
                if (matrix[x][y] <= matrix[nx][ny]) {
                    visted[nx * n + ny] = true;
                    myque.push_back(nx * n + ny);
                    ++ve;
                }
            }
        }

        myque.clear();
        for (int i = 0; i < m; ++i) {
            visted2[i * n + n - 1] = true;
            myque.push_back(i * n + n - 1);
        }
        for (int j = 0; j < (n-1); ++j) {
            visted2[(m-1)*n + j] = true;
            myque.push_back((m-1)*n + j);
        }
        vs = 0, ve = m + n - 1;

        while(vs < ve) {
            x = myque[vs] / n;
            y = myque[vs++] - x * n;

            for (int i = 0; i < 4; ++i) {
                nx = x + d[i][0];
                ny = y + d[i][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (visted2[nx * n + ny])
                    continue;
                if (matrix[x][y] <= matrix[nx][ny]) {
                    visted2[nx * n + ny] = true;
                    myque.push_back(nx * n + ny);
                    ++ve;
                }
            }
        }

        for (x = 0; x < m; x++) 
            for (y = 0; y < n; y++) 
                if (visted[x * n + y] && visted2[x * n + y])
                    res.push_back(vector<int>{x,y});
           

        return res;
    }
};
