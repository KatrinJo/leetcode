/*
lintcode mode
区间重叠
*/

class Solution {
public:
	/**
	* @param s: a string
	* @param dict: a list of strings
	* @return: return a string
	*/
	string addBoldTag(string &s, vector<string> &dict) {
		// write your code here
		if (s.length() == 0 || dict.size() == 0)
			return s;
		string bold[2] = { "<b>", "</b>" };
		set<pair<int, int>> points;
		int l, r, slen = s.length();
		string res;
		bool flag = false;
		for (auto & x : dict) {
			auto p = s.find(x, 0);
			if (p == string::npos)
				continue;
			points.insert(make_pair(p,p + x.length() - 1));
			p = p + x.length();
			while (true) {
				p = s.find(x, p);
				if (p == string::npos)
					break;
				points.insert(make_pair(p, p + x.length() - 1));
				p = p + x.length();
			}
		}
		vector<bool> ifin(slen * 2 , false);
		for (auto & p : points) {
			l = p.first, r = p.second;
			for (int i = 2 * l; i <= 2 * r; i++) {
				ifin[i] = true;
			}
		}
		
		for (int i = 0; i < slen; i++) {
			if (ifin[2 * i]) {
				if (!flag) {
					flag = true;
					res += bold[0];
				}
				res.push_back(s[i]);
			}
			else {
				if (flag) {
					flag = false;
					res += bold[1];
				}
				res.push_back(s[i]);
			}
		}
		if (flag)
			res += bold[1];
		return res;
	}
};
