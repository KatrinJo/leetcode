class Solution {
public:
    string convertToTitle(int n) {
        string res;
        for (; n != 0; n /= 26) {
            --n;
            res.push_back((n % 26) + 'A');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};