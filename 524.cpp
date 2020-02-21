// leetcode的执行用时很迷……

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if (d.size() == 0)
            return "";
        sort(d.begin(), d.end(), [](const string & a, const string & b){
            if (a.length() == b.length()) {
                return a < b;
            }
            return a.length() > b.length();
        });

        for (auto & x : d) {
            if (delmatch(s, x))
                return x;
        }
        return "";
    }

    bool delmatch(string s, string x) {
        int sl = s.length(), xl = x.length();
        int i = 0, j = 0;
        for (i = 0; i < sl && j < xl; ++i) {
            if (s[i] == x[j])
                ++j;
            else
                continue;
        }    
        return (j == xl);    
    }
};


class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if (d.size() == 0)
            return "";
        string res = "";

        for (auto & x : d) {
            if (delmatch(s, x)) {
                if (x.length() == res.length()) {
                    if (res > x)
                        res = x;
                }
                else if (x.length() > res.length()) {
                    res = x;
                }
            }
        }
        return res;
    }

    bool delmatch(string s, string x) {
        int sl = s.length(), xl = x.length();
        int i = 0, j = 0;
        for (i = 0; i < sl && j < xl; ++i) {
            if (s[i] == x[j])
                ++j;
            else
                continue;
        }    
        return (j == xl);    
    }
};