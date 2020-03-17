class Solution {
public:
    void splitarr(vector<string> & res, vector<int> & tmp, const string & s, int idx) {

        if (tmp.size() > 4)
            return;
        if (s.length() - idx > (4 - tmp.size()) * 3) 
            return;  
        if (s.length() - idx < (4 - tmp.size()))
            return;
        for (auto & t : tmp)
            if (t > 255) 
                return;
            
        string num = "";
        if (s.length() == idx) {
            if (tmp.size() == 4) {
                for (auto t: tmp) 
                    num += to_string(t) + ".";
                num.pop_back();
                res.push_back(num);
            }
            return;
        }

        if (s[idx] == '0') {
            tmp.push_back(0);
            splitarr(res, tmp,s, idx + 1);
            tmp.pop_back();
            return;
        }
        tmp.push_back(0);
        for (int i = 0; i < 3 && (idx < s.length()); ++i) {
            tmp.back() = tmp.back() * 10 + s[idx + i] - '0';
            if (tmp.back() > 255)
                break;
            splitarr(res, tmp, s, idx + i + 1);  
        }
        tmp.pop_back();
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4) return {};
        vector<string> res;
        vector<int> tmp;
        splitarr(res, tmp, s, 0);       
        return res;
    }
};