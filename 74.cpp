class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int row = matrix.size(), col = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[row - 1][col - 1])
            return false;
        int l = 0, r = row - 1, m, m2;
        while(l < r) {
            m = (l + r) / 2;
            if (matrix[m][0] == target)
                return true;
            else if (matrix[m][0] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        m = (l + r) / 2;
        if (m < 0)
            m = 0;
        else if (m >= row)
            m = row - 1;
        else if (target < matrix[m][0] && m > 0)
            --m;
        l = 0; r = col - 1;
        while(l < r) {
            m2 = (l + r) / 2;
            if (matrix[m][m2] == target)
                return true;
            else if (matrix[m][m2] > target)
                r = m2 - 1;
            else
                l = m2 + 1;
        }
        m2 = (l + r) / 2;
        if (m2 < 0)
            m2 = 0;
        else if (m2 >= col)
            m2 = col - 1;
        else if (target < matrix[m][m2] && m2 > 0)
            --m2;
        return matrix[m][m2] == target;
    }
};