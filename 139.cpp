// 断断续续写了……太难了……

class Solution {
public:
	struct Node {
		bool canStop;
		Node * child[26];

		Node() {
			canStop = false;
			for (int i = 0; i < 26; ++i)
				child[i] = nullptr;
		}
		~Node() {
			for (int i = 0; i < 26; ++i)
				if (child[i])
					delete child[i];
		}
	};
	void print(Node * root, int num) {
		if (root == nullptr) return;
		cout << "(" << num << ":";
		for (int i = 0; i < 26; ++i) {
			if (root->child[i] != nullptr) {
				cout << (char)(i + 'a') << " ";
				print(root->child[i], num + 1);
			}
		}
		cout << ")";
	}

	Node * root;
	bool wordBreak(string s, vector<string>& wordDict) {
		int sl = s.length();
		if (sl == 0) return true;
		root = new Node();
		root->canStop = true;
		Node * curr;
		bool exist[26] = { false };

		sort(wordDict.begin(), wordDict.end(), [](const string & a, const string & b) {
			return a.length() < b.length();
		});
		for (auto & w : wordDict) {
			if (s == w) return true;
			curr = root;
			if (curr->child[w[0] - 'a'] != nullptr)
				if (sbreak(w, root, 0)) continue;

			for (auto & c : w) {
				if (curr->child[c - 'a'] == nullptr)
					curr->child[c - 'a'] = new Node();
				curr = curr->child[c - 'a'];
				exist[c - 'a'] = true;
			}
			curr->canStop = true;
		}
		for (auto & c : s)
			if (!exist[c - 'a']) return false;
		// print(root, 0);

		int i, j;
		vector<bool> dp(sl + 5, false);
		char c;
		dp[0] = true;
		for (i = 1; i <= sl; ++i) {
			if (!dp[i - 1]) continue;

			curr = root;
			j = i;
			while (j <= sl) {
				c = s[j - 1];
				if (curr->child[c - 'a'] == nullptr) break;
				if (curr->child[c - 'a']->canStop)
					dp[j] = true;
				++j;
				curr = curr->child[c - 'a'];
			}
		}
		return dp[sl];
	}

	bool sbreak(const string & s, const Node * curr, int idx) {
		int l = s.length();
		if (idx == l && curr->canStop) return true;
		if (idx == l) return false;

		char c = s[idx];

		if (curr->child[c - 'a'] == nullptr) return false;

		if (sbreak(s, curr->child[c - 'a'], idx + 1)) return true;

		if (curr->child[c - 'a']->canStop)
			if (sbreak(s, root, idx + 1)) return true;

		return false;
	}
};