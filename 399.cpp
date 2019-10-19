/*
dfs
*/

class Solution {
public:
	map<string, map<string, double> > dis;
	map<string, bool> visted;
	void init() {
		for (auto & x : visted) {
			x.second = false;
		}
	}

	double cal(vector<string> & q, double v) {
		if (q[0] == q[1])
			return v;
		double tmp = -1.0, intermediate = -1.0;
		for (auto & d : dis[q[0]]) {
			if (visted[d.first])
				continue;
			if (d.first == q[1]) {
				return v * d.second;
			}
			visted[d.first] = true;
			vector<string> t{ d.first, q[1] };
			tmp = cal(t, v * d.second);
			if (tmp != -1.0) {
				intermediate = tmp;
			}
			visted[d.first] = false;
		}
		return intermediate;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		dis.clear();
		visted.clear();
		vector<double> res;
		if (queries.empty())
			return res;
		int num = equations.size();
		
		for (int i = 0; i < num; i++) {
			dis[equations[i][0]][equations[i][1]] = values[i];
			dis[equations[i][1]][equations[i][0]] = 1 / values[i];
			dis[equations[i][0]][equations[i][0]] = 1.0;
			dis[equations[i][1]][equations[i][1]] = 1.0;
			visted[equations[i][0]] = false;
			visted[equations[i][1]] = false;
		}
		for (auto & q : queries) {
			if ((dis.find(q[0]) == dis.end()) || (dis.find(q[1]) == dis.end())) {
				res.push_back(-1.0);
			}
			else {
				init();
				visted[q[0]] = true;
				auto d = cal(q, 1.0);
				res.push_back(d);
			}
		}
		return res;
	}
};
