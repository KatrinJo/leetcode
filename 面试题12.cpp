class Solution {
private:
    vector<vector<bool>> visted;
    vector<vector<bool>> valid;
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        int wlen = word.length();
        if (m * n < wlen) return false;
        visted.resize(n, vector<bool>(m, false));
        valid.resize(n, vector<bool>(m,true));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    visted[i][j] = true;
                    if (dfs(board, word, i, j, 0)) return true;
                    visted[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> & board, string word, int x, int y, int curridx) {
        int wlen = word.length();
        if (curridx == wlen - 1) return true;
        // if (x < 0 || x >= n || y < 0 || y >= m) return false;
        int n = board.size(), m = board[0].size();
        int nx, ny;
        vector<int> dir{-1,0,1,0,-1};
        for (int i = 0; i < 4; ++i) {
            nx = x + dir[i], ny = y + dir[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visted[nx][ny]) continue;
            if (board[nx][ny] == word[curridx + 1]) {
                visted[nx][ny] = true;
                if (dfs(board, word, nx, ny, curridx + 1)) 
                    return true;
                visted[nx][ny] = false;
            }
        }
        return false;
    }
};