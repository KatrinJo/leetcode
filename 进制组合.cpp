// 网易往年题

class Solution {
public:

    int getnum(char c) {
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 10;
        return -1;
    }
    int getNumber(string s) {
        if (s.length() == 0)
            return 0;
        int slen = s.length();
        vector<vector<vector<int>>> trans(2, vector<int>(slen, vector<int>(36, -1)));
        int start = getnum(s[0]), tmp;

        for (int i = start; i <= 35; ++i)
            trans[0][0][i] = start;

        for (int i = 1; i < slen; ++i) {
            // 截止到s[i]
            tmp = getnum(s[i]);
            start = max(start, tmp);
            for (int j = start; j <= 35; ++j)
                trans[0][i][j] = trans[0][i - 1][j] * j + tmp;
        }

        start = getnum(s[slen - 1]);
        for (int i = start; i <= 35; ++i)
            trans[1][slen - 1][i] = start;
        
        for (int i = slen - 2; i >= 0; --i) {
            tmp = getnum(s[i]);
            start = max(start, tmp);
            for (int j = start; j <= 35; ++j) {
                trans[1][i][j] = trans[1][i + 1][j] + pow(j, slen - 1 - i) * tmp;
            }
        }

        for (int i = 2; i <= 35; ++i) {
            for (int j = 2; j <= 35; ++j) {
                for (int k = 1; k < slen; ++k) {
                    if (trans[0][k - 1][i] == trans[1][k][j])
                        return trans[0][k - 1][i];
                }
            }
        }
        return -1;
    }
};