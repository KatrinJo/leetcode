// 解法二是计算格子的个数cnt,如果有形成了2x2的方块就--cnt,最后返回2*cnt+2

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0, i, j;
        for (j = 0; j < n; ++j)
            res += grid[0][j];
        for (j = 0; j < n; ++j)
            res += grid[m - 1][j];
        for (i = 0; i < m; ++i)
            res += grid[i][0];
        for (i = 0; i < m; ++i)
            res += grid[i][n - 1];
        for (int i = 0; i < m - 1; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] != grid[i + 1][j]) ++res;
        for (int j = 0; j < n - 1; ++j)
            for (int i = 0; i < m; ++i)
                if (grid[i][j] != grid[i][j + 1]) ++res;
        return res;            
        
    }
};