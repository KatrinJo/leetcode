// 很有趣的排列 需要细心发现规律……

class Solution {
public:
    /**
     * @param s: a string
     * @return: return a list of integers
     */
    vector<int> findPermutation(string &s) {
        // write your code here
        int n = s.length(), i, j, tmp;
        vector<int> res;
        for (i = 0; i <= n; ++i)
            res.push_back(i + 1);
        for (i = 0; i < n; ++i) {
            if (s[i] == 'D') {
                tmp = res[i + 1];
                for (j = i; j >= 0; --j) {
                    if (s[j] == 'I')
                        break;
                    res[j + 1] = res[j];
                }
                res[j + 1] = tmp;
            }
        }
        return res;
    }
};