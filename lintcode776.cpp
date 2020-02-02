//  Strobogrammatic Number II

class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    vector<string> findStrobogrammatic(int n) {
        // write your code here
        if (n == 0)
            return vector<string> {""};
        vector<vector<string>> res{{"0","1","8"},{"11","69","88","96"}};
        if (n == 1)
            return res[0];
        if (n == 2)
            return res[1];
        
        res[1].push_back("00");
        vector<string> two = res[1];

        int maxI = n % 2 ? (n - 1) / 2 : (n / 2 - 1);
        int idx = (n + 1) % 2;
        for (int i = 0; i <= maxI; ++i) {
            res[1-idx].clear();
            for (auto & x : res[idx]) {
                for (auto & y : two) {
                    string tmp = x;
                    tmp.insert(tmp.begin(), y[0]);
                    tmp.push_back(y[1]);
                    // cout << tmp <<endl;
                    res[1-idx].push_back(tmp);
                }
            }
            idx = (idx + 1) % 2;
        }
        
        res[idx].clear();
        for (auto & x : res[1 - idx]) {
            if (x[0] == '0')
                continue;
            res[idx].push_back(x);
        }
        return res[idx];
        
    }
};
