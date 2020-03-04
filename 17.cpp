class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        string num2str[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res, tmp;
        string s = " ";
        for (auto & c : num2str[digits[0] - '0']) {
            s[0] = c;
            res.push_back(s);
        }

        for (int i = 1; i < digits.length(); ++i) {
            for (auto & str : res) {
                s = str + " ";
                for (auto & c : num2str[digits[i] - '0']) {
                    s.back() = c;
                    tmp.push_back(s);
                }
            }
            res.clear();
            res = tmp;
            tmp.clear();
        }

        return res;
    }
};