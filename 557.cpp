class Solution {
public:
    string reverseWords(string str) {
        if (str.length() == 0)
            return "";
        int s = 0, e = 0, i;
        char c;
        while(s < str.length()) {
            e = str.find(' ', s);
            if (e == string::npos) {
                e = str.length();
            }
            --e;
            for (i = s; i <= (s + e) / 2; ++i) {
                c = str[i];
                str[i] = str[s + e - i];
                str[s + e - i] = c;
            }
            s = e + 2;
        }
        return str;
    }
};