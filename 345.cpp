// easy

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos;
        int n = s.length();
        if (n == 0)
            return s;
        // string res = s;
        // A、E、I、O、U
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a' || s[i] == 'u' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e') {
                pos.push_back(i);
            }
            if (s[i] == 'A' || s[i] == 'U' || s[i] == 'I' || s[i] == 'O' || s[i] == 'E') {
                pos.push_back(i);
            }
        }
        int l = pos.size();
        char c;
        for (int i = 0; i < l/2; ++i) {
            c = s[pos[i]];
            s[pos[i]] = s[pos[l-1-i]];
            s[pos[l-1-i]] = c; 
        }
        return s;
    }
};
