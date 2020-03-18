class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> idx(26, -2);
        for (int i = 0; i < s.length(); ++i) {
            if (idx[s[i] - 'a'] == -2) 
                idx[s[i] - 'a'] = i;
            else 
                idx[s[i] - 'a'] = -1;
        }
        int minidx = s.length();
        for (int i = 0; i < 26; ++i) 
            if (idx[i] >= 0) 
                minidx = min(minidx, idx[i]);
        if (minidx == s.length())
            return -1; 
        return minidx;
    }
};