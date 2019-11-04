/*
bfs 记录距离
*/

class Solution {
public:
	/**
	* @param grid: the 2D grid
	* @return: the shortest distance
	*/
	
	bool inMap(int x, int y, int m, int n) {
		return (x >= 0 && x < m && y >= 0 && y < n);
	}
	
	struct point {
		int x;
		int y;
		int d;
		point(int _x, int _y, int _d) {
			x = _x;
			y = _y;
			d = _d;
		}
	};
	int shortestDistance(vector<vector<int>> &grid) {
		// write your code here
		int m = grid.size(), n;
		if (m == 0) return 0;
		n = grid[0].size();
		int x, y, x0, y0, k, d, maxD = m * m * n * n;
		int dxy[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
		vector<vector<int>> dis(m, vector<int>(n, 0));
		vector<long long int> noreach(m, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] != 1) continue;
				vector<long long int> visted(m, 0);
				queue<point> myqueue;
				visted[i] |= 1LL << j;
				myqueue.push(point(i, j, 0));
				while (!myqueue.empty()) {
					auto p = myqueue.front();
					myqueue.pop();
					x = p.x, y = p.y, d = p.d;
					for (k = 0; k < 4; k++) {
						x0 = x + dxy[k][0];
						y0 = y + dxy[k][1];
						if (!inMap(x0, y0, m, n))
							continue;
						if ((visted[x0] >> y0) & 1)
							continue;
						if (grid[x0][y0] != 0)
							continue;
						visted[x0] |= 1LL << y0;
						myqueue.push(point(x0, y0, d + 1));
						dis[x0][y0] += d + 1;
						
					}
				}
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						if (!((visted[i] >> j) & 1))
							noreach[i] |= 1LL << j;
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (((noreach[i] >> j) & 1) || (grid[i][j] != 0))
					continue;
				if (dis[i][j] < maxD) {
					maxD = dis[i][j];
				}
			}
		}
		return maxD;
	}
};
