class Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int> & tmp, vector<int>& nums, int n) {
        if (n == nums.size()) {
            res.push_back(tmp);
            return;
        }
        res.push_back(tmp);
        tmp.push_back(0);
        for (int i = n; i < nums.size(); ++i) {
            tmp.back() = nums[i];
            dfs(res, tmp, nums, i + 1);
        }
        tmp.pop_back();            
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, nums, 0);
        return res;
    }
};