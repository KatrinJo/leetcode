class Solution {
public:

    bool find(vector<int> & nums, int l, int r, int target) {
        int m;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == target) return true;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) return {};
        sort(nums.begin(), nums.end());
        int i, j, k, tmpsum = 0;
        set<pair<int, int>> setpair;
        set<int> left;
        vector<vector<int>> res;

        for (i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            j = i + 1, k = nums.size() - 1;
            while(j < k) {
                tmpsum = nums[i] + nums[j] + nums[k];
                if (tmpsum == 0) {
                    res.push_back(vector<int> {nums[i], nums[j++], nums[k--]});
                    for (; nums[j] == nums[j - 1] && j < k; ++j);
                    for (; nums[k] == nums[k + 1] && j < k; --k);
                }
                else if (tmpsum > 0) {
                    --k;
                }
                else if (tmpsum < 0) {
                    ++j;
                }
            }
        }
        return res;
    }
};