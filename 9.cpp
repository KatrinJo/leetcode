class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int y = 0, tmp = x;
        while(tmp > 0) {
            if (y > ((INT_MAX - (tmp % 10)) / 10))
                return false;
            y = y * 10 + tmp % 10;
            tmp /= 10;
        }
        return x == y;
    }
};