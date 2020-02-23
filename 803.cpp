// TLE...

class Solution {
public:
    void setrelated(vector<vector<int>>& grid, vector<vector<bool>> & related, vector<vector<int>> & father, int x, int y) {
        int dir[5] = {-1,0,1,0,-1};
        int nx, ny;
        int n = grid.size(), m = grid[0].size();
        related[x][y] = true;
        father[x][y] = x * m + y;        
        for (int k = 0; k < 4; ++k) {
            nx = x + dir[k], ny = y + dir[k + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == 0) continue;
            if (related[nx][ny]) continue;
            setrelated(grid, related, father, nx, ny);
        }
    }
    int findparent(vector<vector<int>>& grid, vector<vector<int>>& father, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        if (father[x][y] != x * m + y) {
            int nx = father[x][y] / m, ny = father[x][y] % m;
            father[x][y] = findparent(grid, father, nx, ny);
        }
        return father[x][y];
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> res;
        int n = grid.size(), m =  grid[0].size();
        int x, y, nx, ny;
        int dir[5] = {-1,0,1,0,-1};
        int currp, nextp;
        int tmpx, tmpy, tmp;
        int i, j, ni, nj;
        vector<vector<int>> father(n, vector<int>(m, -1));
        vector<vector<bool>> related;
        for (auto & hit : hits) {
            x = hit[0], y = hit[1];
            if (grid[x][y] == 0) {
                res.push_back(0);
                continue;
            }
            related.clear();
            related.resize(n, vector<bool>(m, false));
            setrelated(grid, related, father, x, y);
            grid[x][y] = 0;
            for (i = 0; i < n; ++i)
                for (j = 0; j < m; ++j) {
                    if (grid[i][j] == 0 || !related[i][j]) continue;
                    father[i][j] = i * m + j;
                }

            for (i = 0; i < n; ++i) {
                for (j = 0; j < m; ++j) {
                    if (grid[i][j] == 0 || !related[i][j]) continue;
                    for (int k = 0; k < 4; ++k) {
                        ni = i + dir[k], nj = j + dir[k + 1];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        if (grid[ni][nj] == 0) continue;
                        nextp = findparent(grid, father, ni, nj);
                        currp = findparent(grid, father, i, j);
                        if (nextp != currp) {
                            tmp = max(nextp, currp);
                            tmpy = tmp % m;
                            tmpx = tmp / m;
                            father[tmpx][tmpy] = min(nextp, currp);
                        }
                    }
                }
            }

            tmp = 0;
            for (i = 0; i < n; ++i) {
                for (j = 0; j < m; ++j) {
                    if (grid[i][j] == 0 || !related[i][j]) continue;
                    tmpx = findparent(grid, father, i, j);
                    tmpy = tmpx % m;
                    tmpx = tmpx / m;
                    if (tmpx != 0) {
                        ++tmp;
                        grid[i][j] = 0;
                    }
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
    
};