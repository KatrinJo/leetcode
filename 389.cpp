class Solution {
public:
    char findTheDifference(string s, string t) {
        int sl = s.length(), i;
        int tchar[26] = {0};
        for (auto & c : t)
            ++tchar[c - 'a'];
        for (auto & c : s)
            --tchar[c - 'a'];
        for (i = 0; i < 26; ++i)
            if (tchar[i])
                break;
        return i + 'a';
    }
};

// 异或……
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto & c : t)
            res ^= c;
        for (auto & c : s)
            res ^= c;
        return res;
    }
};