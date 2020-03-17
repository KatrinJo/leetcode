class Solution {
public:

    bool find(vector<vector<char>>& board, string & word, int x, int y, int idx) {
        if (word.length() == idx)
            return true;
        int dir[5] = {-1, 0, 1, 0, -1};
        int nx, ny;
        bool res = false;
        for (int k = 0; k < 4; ++k) {
            nx = x + dir[k], ny = y + dir[k + 1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
                continue;
            if (board[nx][ny] == word[idx]) {
                board[nx][ny] = '#';
                res = find(board, word, nx, ny, idx + 1);
                board[nx][ny] = word[idx];
            }
            if (res)
                break;
        }
        return res;        
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (find(board, word, i, j, 1))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};