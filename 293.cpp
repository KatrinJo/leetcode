class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        // write your code here
        int n = s.length(), i;
        vector<string> res;
        for (i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1] && s[i] == '+') {
                s[i] = s[i + 1] = '-';
                res.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return res;
    }
};