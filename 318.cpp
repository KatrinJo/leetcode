class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n <= 1) return 0;
        vector<int> len(n);
        vector<unordered_map<char, int>> mymap(n);
        for (int i = 0; i < n; ++i) {
            len[i] = words[i].length();
            for (auto & c : words[i]) {
                ++mymap[i][c];
            }
        }

        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (hassame(mymap[i], mymap[j])) continue;
                res = max(res, len[i] * len[j]);
            }
        }
        return res;
    }

    bool hassame(unordered_map<char, int> & a, unordered_map<char, int> & b) {
        for (auto & x : a) {
            if (b.count(x.first)) 
                return true;
        }
        return false;        
    }
};