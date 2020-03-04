class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        bool flag = false;
        char c;
        int slen1 = num1.length() - 1, slen2 = num2.length() - 1;
        while(slen1 >= 0 && slen2 >= 0) {
            c = num1[slen1] - '0' + num2[slen2] + flag;
            if (c > '9') {
                c -= 10;
                flag = true;
            }
            else
                flag = false;
            res.push_back(c);
            --slen1; --slen2;
        }
        if (slen1 < 0) {
            slen1 = slen2;
            num1 = num2;
        }
        while(slen1 >= 0) {
            c = num1[slen1] + flag;
            if (c > '9') {
                c -= 10;
                flag = true;
            }
            else
                flag = false;
            res.push_back(c);
            --slen1;
        }
        if (flag)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};