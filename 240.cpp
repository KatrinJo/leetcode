class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (n == 0) return false;
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        return search(matrix, 0, 0, m-1, n-1, target);
    }

    bool search(vector<vector<int>>& matrix, int sx, int sy, int ex, int ey, int target) {
        if (sx > ex || sy > ey) return false;
        if (sx < 0 || sx >= matrix.size() || sy < 0 || sy >= matrix[0].size()) return false;
        if (ex < 0 || ex >= matrix.size() || ey < 0 || ey >= matrix[0].size()) return false;
        if (ex - sx <= 1 && ey - sy <= 1) {
			for (int i = sx; i <= ex; ++i) 
                for (int j = sy; j <= ey; ++j) 
                    if (matrix[i][j] == target)
                        return true;
            return false;
        }

        int mx = (sx + ex) / 2, my = (sy + ey) / 2;

        if (matrix[mx][my] > target) {
            if (search(matrix, sx, sy, mx, my, target)) return true;
            if (search(matrix, sx, my + 1, mx - 1, ey, target)) return true;
            if (search(matrix, mx + 1, sy, ex, my - 1, target)) return true;
        }
        else {
            if (search(matrix, mx, my, ex, ey, target)) return true;
            if (search(matrix, sx, my + 1, mx - 1, ey, target)) return true;
            if (search(matrix, mx + 1, sy, ex, my - 1, target)) return true;
        }
        return false;
    }
};


// 这个解法从右上角开始，类似BST，往左是数字减少，往下是数字增大。
// 可太厉害了
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (n == 0) return false;
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int x = 0, y = n - 1;
        while(true) {
            if (x < 0 || x >= m || y < 0 || y >= n) break;
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] > target) --y;
            else if (matrix[x][y] < target) ++x;
        }
        return false;
    }    
};