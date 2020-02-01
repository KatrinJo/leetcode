// easy

class Solution {
public:
    bool isStrobogrammatic(string &num) {
        int n = num.length();
        if (n == 0)
            return true;
        char a, b;
        for (int i = 0; i <= n/2; ++i) {
            a = num[i];
            b = num[n - 1- i];
            if (a == b && (a == '0' || a == '8' || a == '1'))
                continue;
            if ((a == '6' && b == '9') || (a == '9' && b == '6'))
                continue;
            return false;
        }
        return true;
        // write your code here
    }
};
