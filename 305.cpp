// 并查集

class Solution {
public:

	int findParent(vector<int> & vec, int x) {
		if (x < 0 || x >= vec.size()) {
			return -1;
		}
		int p = vec[x];
		if (p == -1) {
			return -1;
		}
		if (p == x) {
			return x;
		}
		vec[p] = findParent(vec, p);
		vec[x] = vec[p];
		return vec[x];
	}

	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		vector<int> res;
		vector<int> grids(n*m, 0);
		int d[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

		for (int i = 0; i < m*n; ++i) {
			grids[i] = -1;
		}
		int cnt = 0, validpcnt = 0;
		int nx = 0, ny = 0, nidx = 0, pidx = 0, parent = -1;
		set<int> setp;
		for (auto p : operators) {
			setp.clear(); 
			validpcnt = 0;
			if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) {
				continue;
			}
			pidx = p.x * m + p.y;
			if (grids[pidx] != -1) {
			    res.push_back(cnt);
				continue;
			}

			grids[pidx] = pidx;
			
			++cnt;
			for (int i = 0; i < 4; ++i) {
				nx = p.x + d[i][0];
				ny = p.y + d[i][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				nidx = nx * m + ny;
				parent = findParent(grids, nidx);
				if (parent != -1) {
					setp.insert(parent);
					++validpcnt;
				}
			}
			for (auto i : setp) {
				grids[i] = pidx;
			}
			cnt = cnt - setp.size(); // +(validpcnt - setp.size());
			res.push_back(cnt);
		}
		return res;
	}
};
