class Solution {
public:

    int dfs(vector<int> & bitint, vector<int> & len, int num, int sumlen, int last) {
        int maxlen = sumlen;
        for (int i = last; i < len.size(); ++i) {
            if ((bitint[i] & num) == 0) {
                maxlen = max(maxlen, dfs(bitint, len, num | bitint[i], sumlen + len[i], i + 1));
            }
        }
        return maxlen;
    }

    int maxLength(vector<string>& arr) {
        vector<int> bitint;
        vector<int> len;
        int tmp;
        for (auto & s: arr) {
            tmp = 0;
            for (char c : s) {
                if (tmp & (1 << (c - 'a'))) {
                    tmp = 0;
                    break;
                }
                tmp |= (1 << (c - 'a'));
            }
            if (tmp != 0) {
                bitint.push_back(tmp);
                len.push_back(s.length());
            }
        }
        if (len.size() == 0)
            return 0;
        
        return dfs(bitint, len, 0, 0, 0);
    }
};