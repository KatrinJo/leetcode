class Solution {
public:
    
    void gen(vector<vector<int>>& res, vector<int>& candidates, vector<int> & curr, int num, int target) {
        if(target == 0) {
            res.push_back(curr);
            return;            
        }
        if (num >= candidates.size() || target < 0)
            return;
        int e;
        for (e = num + 1; e < candidates.size(); ++e) 
            if (candidates[e] != candidates[e - 1])
                break;
        gen(res, candidates, curr, e, target);
        for (int k = 0; k < (e - num); ++k) {
            curr.push_back(candidates[num]);
            gen(res, candidates, curr, e, target - candidates[num] * (k + 1));
        }
        for (int k = 0; k < (e - num); ++k)
            curr.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return {};
        vector<vector<int>> res;
        vector<int> tmp{};
        sort(candidates.begin(), candidates.end());
        gen(res, candidates, tmp, 0, target);
        return res;
    }
};