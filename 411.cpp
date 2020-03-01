// 感觉写得很繁琐……

class Solution {
public:
	/**
	* @param target: a target string
	* @param dictionary: a set of strings in a dictionary
	* @return: an abbreviation of the target string with the smallest possible length
	*/

	struct Node {
		Node * child[26];
		Node() {
			for (int i = 0; i < 26; ++i)
				child[i] = nullptr;
		}
		~Node() {
			for (int i = 0; i < 26; ++i)
				if (child[i] != nullptr)
					delete child[i];
		}
	};

	Node * buildTree(string & target, vector<string> & dict) {
		Node * root = new Node();
		Node * tmp;
		int sl, i, tl = target.length();
		for (auto & x : dict) {
			tmp = root;
			sl = x.length();
			if (sl != tl) continue;
			for (i = 0; i < sl; ++i) {
				if (tmp->child[x[i] - 'a'] == nullptr)
					tmp->child[x[i] - 'a'] = new Node();
				tmp = tmp->child[x[i] - 'a'];
			}
			tmp->canstop = true;
		}
		return root;
	}

	vector<string> getvec(string & target) {
		int n = target.length(), i, j;
		vector<vector<string>> res(n);
		string tmp = "1", sint;
		res[0].push_back(tmp);
		tmp[0] = target[0];
		res[0].push_back(tmp);

		int xl;
		for (i = 1; i < n; ++i) {
			// res[i].push_back(to_string(i + 1));
			for (auto & x : res[i - 1]) {
				tmp = x;
				tmp.push_back(target[i]);
				res[i].push_back(tmp);
				if (x.back() >= '0' && x.back() <= '9') {
					xl = x.length();
					for (j = xl - 1; j >= 0; --j)
						if (!(x[j] >= '0' && x[j] <= '9')) break;
					sint = x.substr(j + 1, xl - j - 1);
					res[i].push_back(x.substr(0, j + 1) + to_string(stoi(sint) + 1));
				}
				else {
					tmp.back() = '1';
					res[i].push_back(tmp);
				}
			}
		}
		return res[n - 1];
	}

	string minAbbreviation(string &target, vector<string> &dictionary) {
		// Write your code here
		int sl = target.length();
		if (sl == 0) return "";
		if (sl == 1) return target;

		vector<string> res = getvec(target);
		sort(res.begin(), res.end(), [](const string & a, const string & b) {
			if (a.length() == b.length())
				return a < b;
			return a.length() < b.length();
		});

		Node * root = buildTree(target, dictionary);
		for (auto & x : res) {
			if (isabbr(x, 0, root)) continue;
			return x;
		}
		return "";
	}

	bool isabbr(string & str, int idx, Node * root) {
		int sl = str.length();
		if (idx == sl) return true;

		Node * tmp = root;
		char c = str[idx];
		int i, j, num;
		if (c >= '0' && c <= '9') {
			for (j = idx + 1; j < sl; ++j) {
				if (!(str[j] >= '0' && str[j] <= '9')) {
					break;
				}
			}
			num = stoi(str.substr(idx, j - idx));
			bool flag = false;
			queue<pair<Node*, int>> myque;
			myque.push(make_pair(root, 0));
			while (!myque.empty()) {
				auto x = myque.front();
				myque.pop();
				tmp = x.first;
				for (i = 0; i < 26; ++i) {
					if (tmp->child[i] != nullptr) {
						if (x.second == num - 1) {
							if (isabbr(str, j, tmp->child[i])) {
								return true;
							}
						}
						else
							myque.push(make_pair(tmp->child[i], x.second + 1));
					}
				}
			}
			return false;
		}
		else {
			if (root->child[c - 'a'] == nullptr) return false;
			return isabbr(str, idx + 1, root->child[c - 'a']);
		}
	}
};


// 不用Trie字典树的话，速度又慢得很……

class Solution {
public:
	/**
	* @param target: a target string
	* @param dictionary: a set of strings in a dictionary
	* @return: an abbreviation of the target string with the smallest possible length
	*/

	vector<string> getvec(string & target) {
		int n = target.length(), i, j;
		vector<vector<string>> res(n);
		string tmp = "1", sint;
		res[0].push_back(tmp);
		tmp[0] = target[0];
		res[0].push_back(tmp);

		int xl;
		for (i = 1; i < n; ++i) {
			// res[i].push_back(to_string(i + 1));
			for (auto & x : res[i - 1]) {
				tmp = x;
				tmp.push_back(target[i]);
				res[i].push_back(tmp);
				if (x.back() >= '0' && x.back() <= '9') {
					xl = x.length();
					for (j = xl - 1; j >= 0; --j)
						if (!(x[j] >= '0' && x[j] <= '9')) break;
					sint = x.substr(j + 1, xl - j - 1);
					res[i].push_back(x.substr(0, j + 1) + to_string(stoi(sint) + 1));
				}
				else {
					tmp.back() = '1';
					res[i].push_back(tmp);
				}
			}
		}
		return res[n - 1];
	}

	string minAbbreviation(string &target, vector<string> &dictionary) {
		// Write your code here
		int sl = target.length();
		if (sl == 0) return "";
		if (sl == 1) return target;

		vector<string> res = getvec(target);
		sort(res.begin(), res.end(), [](const string & a, const string & b) {
			if (a.length() == b.length())
				return a < b;
			return a.length() < b.length();
		});

        bool flag;
		for (auto & x : res) {
		    flag = true;
		    for (auto & y : dictionary) {
		        if (y.length() != sl) 
		            continue;
		        if (isabbr(x, 0, y, 0)) {
		            flag = false;
		            break;
		        }
		    }
			if (flag)
    			return x;
		}
		return "";
	}

	bool isabbr(string & a, int idxa, string & b, int idxb) {
		int alen = a.length();
		if (idxa == alen) 
		    return true;
		int i, j, num;
		char c = a[idxa];
		if (c >= '0' && c <= '9') {
		    for (j = idxa + 1; j < alen; ++j) 
		        if (!(a[j] >= '0' && a[j] <= '9'))
		            break;
		    num = stoi(a.substr(idxa, j - idxa));
		    return isabbr(a, j, b, idxb + num);
		}
		else {
		    if (c != b[idxb])
		        return false;
		    return isabbr(a, idxa + 1, b, idxb + 1);
		}
	}
};