class Solution {
public:
    struct CIdx {
        int idx;
        char c;
        CIdx(int _idx, char _c) {
            idx = _idx;
            c = _c;
        }
        bool operator < (const CIdx & c) const {
            return idx > c.idx;
        }
    };
    string minWindow(string s, string t) {
        if (s == "" || t == "" || s.length() < t.length())
            return "";
        map<char, int> cnts, cntt;
        for (auto c : s)
            cnts[c]++;
        for (auto c : t) {
            cntt[c]++;
            if (cnts.find(c) == cnts.end())
                return "";
            if (cntt[c] > cnts[c])
                return "";
        }
        priority_queue<CIdx> myque;
        int i = 0, rest = t.length();
        int si, ei, minlen = s.length() + 2;
        for (i = 0; i < s.length(); ++i) {
            if (cntt.find(s[i]) == cntt.end())
                continue;
            
            myque.push(CIdx(i, s[i]));
            --cntt[s[i]];
            if (cntt[s[i]] >= 0) 
                --rest;
            
            while(!myque.empty()) {
                auto tmp = myque.top();
                if (cntt[tmp.c] >= 0)
                    break;
                cntt[tmp.c]++;
                myque.pop();
            }

            if (rest == 0) {
                auto tmp = myque.top();
                if (i - tmp.idx + 1 < minlen) {
                    minlen = i - tmp.idx + 1;
                    si = tmp.idx;
                    ei = i;
                }
            }
        }
        return s.substr(si, ei - si + 1);
    }
};