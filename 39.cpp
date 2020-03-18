class Solution {
public:
    void gen(vector<vector<int>>& res, vector<int>& candidates, vector<int> curr, int num, int target) {
        if(target == 0) {
            res.push_back(curr);
            return;            
        }
        if (num >= candidates.size()) {
            return;
        }
        gen(res, candidates, curr, num + 1, target);
        while(target >= candidates[num]) {
            curr.push_back(candidates[num]);
            target -= candidates[num];
            gen(res, candidates, curr, num + 1, target);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        gen(res, candidates, {}, 0, target);
        return res;        
    }
};