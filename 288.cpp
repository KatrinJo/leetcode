/*
用的是lintcode格式
效率不是很高
*/
class ValidWordAbbr {
public:
	/*
	* @param dictionary: a list of words
	*/
	string int2str(int n) {
		string ret = "";
		while (n > 0) {
			ret.push_back(n % 10 + '0');
			n /= 10;
		}
		ret.assign(ret.rbegin(), ret.rend());
		return ret;
	}
	map<string, int> cnt;
	map<string, int> dict;

	ValidWordAbbr(vector<string> dictionary) {
		int l;
		string t;
		for (auto & s : dictionary) {
			l = s.length();
			if (l <= 2)
				continue;
			t.clear();
			t.push_back(s[0]);
			t += int2str(l - 2);
			t.push_back(s[l - 1]);

			if (dict.find(t) == dict.end())
				dict[t] = 1;
			else
				dict[t] += 1;

			if (cnt.find(s) == cnt.end())
				cnt[s] = 1;
			else
				cnt[s] += 1;
		}
	}

	bool isUnique(string &word) {
		int l = word.length();;
		string t;
		if (l <= 2)
			return true;
		t.clear();
		t.push_back(word[0]);
		t += int2str(l - 2);
		t.push_back(word[l - 1]);
		if (dict.find(t) == dict.end())
			return true;
		auto res = dict[t];
	
		if (cnt.find(word) != cnt.end()) {
			if (res == cnt[word])
				return true;
		}

		return false;
	}
};
