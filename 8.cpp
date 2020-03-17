class Solution {
public:
    int myAtoi(string str) {
        long long int num = 0;
        bool minus = false;
        int i;
        for (i = 0; i < str.length() && str[i] == ' '; ++i);
        if (i == str.length()) return 0;
        if (str[i] == '-' || str[i] == '+') {
            minus = (str[i] == '-'); 
            ++i;
        }

        for (; i < str.length(); ++i) {
            if (!(str[i] >= '0' && str[i] <= '9')) break;
            num = num * 10 + str[i] - '0';
            if (minus && num - 1 >= INT_MAX)
                return INT_MIN;
            if (!minus && num >= INT_MAX)
                return INT_MAX;
        }
        return minus ? -num : num;
    }
};