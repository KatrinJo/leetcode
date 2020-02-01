// 冒泡

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int n = people.size();
		if (n == 0)
			return people;
		sort(people.begin(), people.end(), [](const vector<int> & a, const vector<int> & b) {
			if (a[0] == b[0]) {
				return a[1] < b[1];
			}
			return a[0] > b[0];
		});
		vector<int> tmp;
		for (int i = 1; i < n; ++i) {
			tmp.clear();
			tmp = people[i];
			if (i > people[i][1]) {
				for (int k = i; k > tmp[1]; --k) {
					people[k] = people[k - 1];
				}
				people[tmp[1]] = tmp;
			}
		}
		return people;
	}
};
