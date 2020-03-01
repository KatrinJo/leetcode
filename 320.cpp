class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        // Write your code here
        int n = word.length();
        if (n == 0) return {};
        vector<vector<string>> res(n + 1);
        
        string tmp, dis;
        tmp.push_back(word[0]);
        res[0].push_back(tmp);
        res[0].push_back("1");
        
        for (int i = 1; i < n; ++i) {
            res[i].push_back(to_string(i + 1));
            for (int j = 0; j < i; ++j) {
                dis = to_string(i - j);
                for (auto & x : res[j]) {
                    if (x.back() >= '0' && x.back() <= '9') continue;
                    tmp = x + dis;
                    res[i].push_back(tmp);              
                }
            }
            for (auto & x : res[i - 1]) {
                tmp = x;
                tmp.push_back(word[i]);
                res[i].push_back(tmp);              
            }
        }
        return res[n - 1];
    }
};