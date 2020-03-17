class Solution {
public:
    bool dfs(const vector<vector<char>> & board, vector<int> & visted, string & w, int idx, int x, int y) {
        if (w.length() == idx)
            return true;
        int dir[5] = {-1, 0, 1, 0, -1}, nx, ny;
        for (int k = 0; k < 4; ++k) {
            nx = x + dir[k], ny = y + dir[k + 1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
                continue;
            if ((visted[nx] & (1 << ny)))
                continue;
            if (board[nx][ny] == w[idx]) {
                visted[nx] ^= (1 << ny);
                if (dfs(board, visted, w, idx + 1, nx, ny)) 
                    return true;
                visted[nx] ^= (1 << ny);
            }
        }
        return false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0 || board[0].size() == 0) return {};
        vector<int> visted;
        vector<string> res;
        bool flag = false;
        for (auto & w : words) {
            visted.clear();
            visted.resize(board.size(), 0);
            flag = false;
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (board[i][j] == w[0]) {
                        visted[i] ^= (1 << j);
                        if (dfs(board, visted, w, 1, i, j)) {
                            res.push_back(w);
                            visted[i] ^= (1 << j);
                            flag = true;
                            break;
                        }
                        visted[i] ^= (1 << j);
                    }
                }
                if (flag) break;
            }
        }
        return res;
    }
};