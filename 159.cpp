// Solution只适合2个字母的情况。其实也可以改成k个，只要记录k个字母的顺序（方便替换）。应该还可以简化。
// Solution2是网上直接将2替换成k即可的解。很有趣。
// 就效率上来讲Solution2明显优于Solution。

class Solution {
public:
	/**
	* @param s: a string
	* @return: the length of the longest substring T that contains at most 2 distinct characters
	*/
	int lengthOfLongestSubstringTwoDistinct(string &s) {
		int n = s.length(), delIdx = 0;
		vector<int> idxIntwoChars(128, 0), idxRight(128, 0);
		for (int i = 0; i < 128; i++) {
			idxIntwoChars[i] = idxRight[i] = -1;
		}
		string twoChars = "";
		int lastIdx = -1, maxLen = 0;

		for (int i = 0; i < n; i++) {
			idxRight[s[i]] = i;

			if (idxIntwoChars[s[i]] > -1) {
				maxLen = maxLen > (i - lastIdx) ? maxLen : (i - lastIdx);
				continue;
			}
			else {
				if (twoChars.length() == 2) {
					delIdx = 1 - idxIntwoChars[s[i-1]];
					lastIdx = idxRight[twoChars[delIdx]];
					idxIntwoChars[twoChars[delIdx]] = -1;
					idxIntwoChars[s[i]] = delIdx;
					twoChars[delIdx] = s[i];
					maxLen = maxLen > (i - lastIdx) ? maxLen : (i - lastIdx);
				}
				else {
					idxIntwoChars[s[i]] = twoChars.length();
					twoChars.push_back(s[i]);
					maxLen = i + 1;
				}
			}
		}
		return maxLen;
	}
};

class Solution2 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > 2) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
