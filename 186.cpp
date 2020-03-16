class Solution {
public:
    /**
     * @param str: a string
     * @return: return a string
     */
    string reverseWords(string &str) {
        // write your code here
        if (str.length() == 0)
            return "";
        int len = str.length(), i;
        char c;
        for (i = 0; i < len / 2; ++i) {
            c = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = c;
        }
        
        int l = 0, r;
        while(l < len) {
            r = str.find(" ", l);
            if (r < 0) {
                r = len;
            }
            for (i = 0; i < (r - l) / 2; ++i) {
                c = str[l + i];
                str[l + i] = str[r - 1 - i];
                str[r - 1 - i] = c;
            }
            l = r + 1;
            
        }
        return str;
    }
};