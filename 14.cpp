class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string res = strs[0];
        int j, slen = res.length();
        for (int i = 1; i < strs.size(); ++i) {
            if (res == "")
                break;
            if (strs[i].length() > slen)
                slen = strs[i].length();
            for (j = 0; j < slen && res[j] == strs[i][j]; ++j);
            res = res.substr(0, j);
            slen = j;
        }
        return res;
    }
};