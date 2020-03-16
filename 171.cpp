class Solution {
public:
    int titleToNumber(string s) {
        if (s.length() == 0) return 0;
        int num = 0;
        for (char c : s) {
            if (num >= ((INT_MAX - c - 1 + 'A') / 26)) {
                num = INT_MAX;
                break;
            }
            num = num * 26 + c - 'A' + 1;
        }
        return num;
    }
};