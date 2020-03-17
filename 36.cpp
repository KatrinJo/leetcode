class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, rect[9] = {0}, tmp, i, j;
        for (i = 0; i < 9; ++i) {
            for (j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                tmp = (1 << (board[i][j] - '1'));
                if ((row[i] & tmp) || (col[j] & tmp) || (rect[(i / 3)* 3 + (j / 3)] & tmp)) return false;
                row[i] |= tmp;
                col[j] |= tmp;
                rect[(i / 3)* 3 + (j / 3)] |= tmp;
            }
        }
        return true;
    }
};