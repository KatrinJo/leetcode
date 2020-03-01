class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        if (rooms.size() == 0) return;
        int m = rooms.size(), n = rooms[0].size();
        if (n == 0) return;
        const int dir[5] = {-1, 0, 1, 0, -1};
        vector<pair<int,int>> myque;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) 
                if (rooms[i][j] == 0) 
                    myque.push_back(make_pair(i * n + j, 0));
        int s = 0, e = myque.size();
        int x, y, step;
        int nx, ny;
        while(s < e) {
            auto & t = myque[s];
            ++s;
            x = t.first / n, y = t.first % n;
            step = t.second;
            for (int k = 0; k < 4; ++k) {
                nx = x + dir[k], ny = y + dir[k + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (rooms[nx][ny] <= step + 1) continue;
                rooms[nx][ny] = step + 1;
                myque.push_back(make_pair(nx * n + ny, step + 1));
                ++e;
            }
        }
    }
};