// 虽然理清了点是怎么产生的，但是TLE了。
// 可以把点拆成[x_left, height, 's'],[x_right, height, 'e']维护一个有限队列，当遇到's'点的时候就比较最大高度和height，如果要把height更新为最大高度，否则过。遇到'e'点的时候也比较最大高度和height，如果一致就退出，并把最大高度设为优先队列里的下一个。

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		int n = buildings.size();
		vector<vector<int>> tmp, res, res2;
		if (n == 0) {
			return res;
		}
		else if (n == 1) {
			res.push_back(vector<int>{buildings[0][0], buildings[0][2]});
			res.push_back(vector<int>{buildings[0][1], 0});
			return res;
		}
		sort(buildings.begin(), buildings.end(),
			[](const vector<int> & a, const vector<int> & b) {
			if (a[1] == b[1]) {
				if (a[2] == b[2])
					return a[0] < b[0];
				return a[2] > b[2];
			}
			return a[1] < b[1];
		});
		// TODO: check i=0;i<n;++i

		for (int i = 0; i < n; ++i) {
			auto & b = buildings[i];
			bool flag = false;
			tmp.clear();
			for (int j = 0; j < i; ++j) {
				auto & jb = buildings[j];
				if (b[0] < jb[1] && jb[1] < b[1] && jb[2] > b[2]) {
					bool tmpflag = false;
					for (int k = j + 1; k < n; ++k) {
						auto & kb = buildings[k];
						if (kb[0] <= jb[1] && jb[1] < kb[1] && kb[2] > b[2]) {
							tmpflag = true;
							break;
						}

					}
					if (!tmpflag)
						res.push_back(vector<int>{jb[1], b[2]});
					//flag = true;
				}
			}
			for (int j = i + 1; j < n; j++) {
				auto & jb = buildings[j];
				if (b[1] > jb[0])
					flag = true;
			}
			if (!flag)
				res.push_back(vector<int>{b[1], 0});
		}
		sort(buildings.begin(), buildings.end(),
			[](const vector<int> & a, const vector<int> & b) {
			if (a[0] == b[0]) {
				if (a[2] == b[2])
					return a[1] < b[1];
				return a[2] > b[2];
			}
			return a[0] < b[0];
		});
		for (int i = 1; i < n; ++i) {
			auto & b = buildings[i];
			bool flag = false;
			for (int j = 0; j < i; ++j) {
				auto & jb = buildings[j];
				if (jb[0] < b[0] && b[0] < jb[1] && jb[2] > b[2])
					flag = true;
			}
			if (!flag)
				res.push_back(vector<int>{b[0], b[2]});
		}
		res.push_back(vector<int>{buildings[0][0], buildings[0][2]});
		sort(res.begin(), res.end(),
			[](const vector<int> & a, const vector<int> & b) {
			if (a[0] == b[0]) {
				return a[1] > b[1];
			}
			return a[0] < b[0];
		});

		int m = res.size(), l = res[0][0];
		res2.push_back(res[0]);

		for (int i = 1; i < m; ++i) {
			if (res[i][0] == l)
				continue;
			res2.push_back(res[i]);
			l = res[i][0];
		}

		res.clear();
		m = res2.size(), l = res2[0][1];
		res.push_back(res2[0]);
		for (int i = 1; i < m; ++i) {
			if (res2[i][1] == l)
				continue;
			res.push_back(res2[i]);
			l = res2[i][1];
		}

		return res;
	}
};
