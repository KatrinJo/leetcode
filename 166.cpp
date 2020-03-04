// 边界条件一定要考虑了……

class Solution {
public:
	string fractionToDecimal(int numerator0, int denominator0) {
		if (denominator0 == 0) return "";
		if (numerator0 == 0) return "0";
        bool flag = false;
        long long int numerator = numerator0;
        long long int denominator = denominator0;
        if (numerator < 0 && denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        else if (numerator < 0 || denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
            flag = true;
        }
		long long int k = numerator / denominator;
		numerator -= denominator * k;
		string res = to_string(k);
		if (numerator == 0) {
            if (flag)
                res = "-" + res;
            return res;
        }
		res.push_back('.');

        string tmp;
        unordered_map<long long int, int> mymap;
        while(numerator > 0) {
            if (mymap.count(numerator)) {
                int idx = mymap[numerator];
                int len = tmp.length();
                if (idx >= 1)
                    tmp = tmp.substr(0, idx) + "(" + tmp.substr(idx, len - idx) + ")";
                else
                    tmp = "(" + tmp.substr(idx, len - idx) + ")";
                res += tmp;
                break;
            }
            mymap[numerator] = tmp.length();
            numerator *= 10;
            k = numerator / denominator;
            numerator -= k * denominator;
            tmp.push_back('0' + k);
            if (numerator == 0) {
                res += tmp;
                break;
            }
        }
        if (flag)
            res = "-" + res;
		return res;
	}
};