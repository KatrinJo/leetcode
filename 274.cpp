// 对二分搜索真的不清楚怎么写……

class Solution {

public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		if (n == 0) return n;
		if (n == 1) return min(1, citations[0]);
		sort(citations.begin(), citations.end());
		return find(citations, 0, min(n, citations[n - 1]));
	}

	int find(vector<int>& citations, int l, int r) {
		if (l == r) return l;
		int m = (l + r) / 2;
		auto cnt = findidx(citations, m);

		if (cnt[2] > m) {
			return find(citations, m + 1, r);
		}
		else if (cnt[1] + cnt[2] < m) {
			return find(citations, l, m - 1);
		}
		else {
			return m;
		}
	}

	vector<int> findidx(const vector<int>& citations, int val) {
		int n = citations.size();
		if (val < citations[0]) return vector<int>{0, 0, n};
		if (val > citations.back()) return vector<int>{n, 0, 0};
		vector<int> res(3, 0);
		int sameleft = 0, sameright = 0;

		int l = 0, r = n - 1, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (citations[m] < val)
				l = m + 1;
			else if (citations[m] == val)
				break;
			else
				r = m - 1;
		}

		if (citations[m] != val) {
			for (l = m - 1; l < n; ++l) {
				if (l < 0) continue;
				if (citations[l] >= val) break;
			}
			res[0] = l;
			res[2] = n - l;
		}
		else {
			res[0] = res[2] = m;
			while (res[0] >= 0) {
				if (citations[res[0]] != val) {
					++res[0];
					break;
				}
				--res[0];
			}
			if (res[0] < 0) res[0] = 0;
			while (res[2] < n) {
				if (citations[res[2]] != val) {
					--res[2];
					break;
				}
				++res[2];
			}
			if (res[2] >= n) res[2] = n - 1;
			res[1] = res[2] - res[0] + 1;
			res[2] = n - 1 - res[2];
		}

		return res;
	}
};