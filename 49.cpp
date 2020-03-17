class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0)
            return {};
        vector<int> num(strs.size(), 0);
        map<string, int> mymap;
        vector<vector<string>> res;
        string tmp;
        for (int i = 0; i < strs.size(); ++i) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (mymap.find(tmp) == mymap.end()) {
                mymap[tmp] = mymap.size();
                res.push_back({});
            }
            res[mymap[tmp]].push_back(strs[i]);
        }
        return res;
    }
};