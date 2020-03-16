class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        int maxLen = 0, tmplen = 0;
        string res;
        for (int i = 0; i < 2 * s.length() - 1; ++i) {
            tmplen = 0;
            if (i % 2 == 0) {
                while(tmplen < s.length()) {
                    if ((i/2 - tmplen - 1) < 0 || (i/2 + tmplen + 1) >= s.length()) break;
                    if (s[i/2 - tmplen - 1] != s[i/2 + tmplen + 1]) break;
                    ++tmplen;
                }
                if (2 * tmplen + 1 > maxLen) {
                    res = s.substr(i/2 - tmplen, 2 * tmplen + 1);
                    maxLen = 2 * tmplen + 1;
                }
            }
            else {
                while(tmplen < s.length()) {
                    if (((i - 1)/2 - tmplen) < 0 || ((i+1)/2 + tmplen) >= s.length()) break;
                    if (s[(i - 1)/2 - tmplen] != s[(i+1)/2 + tmplen]) break;
                    ++tmplen;
                }
                if (2 * tmplen > maxLen) {
                    res = s.substr((i - 1)/2 - tmplen + 1, 2 * tmplen);
                    maxLen = 2 * tmplen;
                }
            }
        }
        return res;
    }
};


// manacher
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        string news;
        for (int i = 0; i < (s.length() << 1) + 1; ++i) {
            news.push_back((i & 1) == 0 ? '#' : s[i >> 1]);
        }
        vector<int> P(news.length(), 0);
        string res;
        int C, R, maxlen = 0;

        for (int i = 0; i < news.length(); ++i) {
            if (i < R) 
                P[i] = min(P[C << 1 - i], R - i);
            else 
                P[i] = 1;

            while((i - P[i] >= 0) && (i + P[i] < news.length())) {
                if (news[i - P[i]] != news[i + P[i]]) break;
                ++P[i];
            }
            if (P[i] > maxlen) {
                C = i;
                maxlen = P[i];
            }
        }
        news = news.substr(C - maxlen + 1, maxlen * 2 - 1);
        for (auto c : news) {
            if (c == '#') continue;
            else res.push_back(c);
        }
        return res;
    }
};