class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0)
            return 0;
        if (board[0].size() == 0)
            return 0;
        int m = board.size(), n = board[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.')
                    continue;
                if (i >= 1 && board[i - 1][j] == 'X')
                    continue;
                if (j >= 1 && board[i][j - 1] == 'X')
                    continue;
                ++res;
            }
        }
        return res;
    }
};