// 写得比较难看。bfs找连通块。

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		//vector<vector<char>> grid = grids;
		int n = grid.size();
		if (n == 0) {
			return 0;
		}
		int m = grid[0].size();
		if (m == 0) {
			return 0;
		}
		int d[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

		vector<int> myque;
		int vs = 0, ve = 0;
		int x = 0, y = 0, nx = 0, ny = 0;
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == '*' || grid[i][j] == '0') {
					grid[i][j] = '*';
					continue;
				}
				myque.clear();
				myque.push_back(i * m + j);
				grid[x][y] = '*';
				vs = 0, ve = 1;
				++res;
				while (vs < ve) {
					x = myque[vs] / m;
					y = myque[vs] - m * x;
					++vs;
					for (int k = 0; k < 4; k++) {
						nx = x + d[k][0];
						ny = y + d[k][1];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
							continue;
						}
						if (grid[nx][ny] == '*' || grid[nx][ny] == '0') {
							grid[nx][ny] = '*';
							continue;
						}
						if (grid[nx][ny] == '1') {
							grid[nx][ny] = '*';
							myque.push_back(nx * m + ny);
							++ve;
						}
					}
				}
			}
		}
		return res;
	}
};
