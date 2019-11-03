/*
进阶——
原地算法：利用多余的位信息（比如高位）
*/

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())
			return;
		if (board[0].empty())
			return;
		vector<vector<int>> tmp = board;
		int d[8][2] = { {-1,0},{ 1,0 },{ 0,-1 },{ 0,1 },{1,1},{ 1,-1 },{ -1,1 },{ -1,-1 } };
		int m = tmp.size(), n = tmp[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int ti = i + d[k][0], tj = j + d[k][1];
					if (ti < 0 || ti >= m || tj < 0 || tj >= n)
						continue;
					cnt += tmp[ti][tj];
				}
				if (tmp[i][j] == 1) {
					if (cnt < 2 || cnt > 3)
						board[i][j] = 0;
				}
				else {
					if (cnt == 3)
						board[i][j] = 1;
				}
			}
		}
	}
};
