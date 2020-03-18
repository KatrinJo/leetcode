class Solution {
public:
    bool isValidChar(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
    bool isValidNum(char c) {
        return (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(!isValidChar(s[i]) && !isValidNum(s[i]) && i < j)
                ++i;
            while(!isValidChar(s[j]) && !isValidNum(s[j]) && i < j)
                --j;
            if (isValidNum(s[i]) && isValidNum(s[j])) {
                if (s[i] != s[j])
                    return false;
            }
            else if (isValidNum(s[i]) || isValidNum(s[j])) {
                return false;
            }
            else {
                if (toupper(s[i]) != toupper(s[j]))
                    return false;
            }
            ++i, --j;
        }
        return true;
    }
};