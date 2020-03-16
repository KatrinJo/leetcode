class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0) return 0;
        map<char, int> c2n = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
        
        int curr = 0, cnt = 0, res = 0;
        curr = c2n[s[0]];
        for (char c : s) {
            if (curr > c2n[c]) {
                res += (curr * cnt);
                curr = c2n[c];
                cnt = 1;
            }
            else if (curr < c2n[c]) {
                res -= (curr * cnt);
                curr = c2n[c];
                cnt = 1;
            }
            else {
                ++cnt;
            }
        }
        res += curr * cnt;
        return res;
    }

};