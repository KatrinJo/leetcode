// 回溯

class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the palindromic permutations (without duplicates) of it
     */
    vector<string> generatePalindromes(string &s) {
        // write your code here
        int n = s.length();
        if (n == 0) return {};
        if (n == 1) return vector<string>{s};
        vector<int> m(26, 0);
        for (int i = 0; i < n; ++i)
            m[s[i]-'a'] += 1;
        int cnt = 0, idx = -1;
        for (int i = 0; i < 26; ++i) 
            if (m[i] % 2) {
                ++cnt;
                idx = i;
            }
        
        if(cnt > 1) return {};
        if (cnt == 1) --m[idx];
        vector<string> res;
        string tmp = "";
        generate(res, tmp, m);
        int ressize = res.size();
        string part;
        for (int i = 0; i < ressize; ++i) {
            part.assign(res[i].rbegin(), res[i].rend());
            if (cnt) 
                res[i].push_back(idx + 'a');
            res[i] += part;
        }
        return res;
        
    }
    
    void generate(vector<string> & res, string & s, vector<int> & m) {
        bool flag = true;
        int i;
        int n = m.size();
        for (i = 0; i < n; ++i) {
            if (m[i] > 0) {
                flag = false;
                s.push_back('a' + i);
                m[i] -= 2;
                generate(res, s, m);
                m[i] += 2;
                s.pop_back();
            }
        }
        if (flag)
            res.push_back(s);
    }
};