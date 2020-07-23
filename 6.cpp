class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= numRows || numRows == 1)
            return s;
        int slen = s.length();
        string newstr = "";
        int sub = 2 * (numRows - 1);
        for (int i = 0; i < slen; i += sub)
            newstr.push_back(s[i]);
        for (int i = 1; i < numRows - 1; ++i) {
            newstr.push_back(s[i]);
            for (int j = sub; j < slen + i; j += sub) {
                newstr.push_back(s[j - i]);
                if (j + i >= slen)
                    continue;
                newstr.push_back(s[j + i]);
            }
        }
        
        for (int i = sub / 2; i < slen; i += sub)
            newstr.push_back(s[i]);
        return newstr;        
    }
};