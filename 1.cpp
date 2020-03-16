class Solution {
public:

    int find(vector<int> & nums, int l, int r, int target) {
        int m;
        while(l <= r) {
            m = (l + r) / 2;
            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] == target)
                return m;
            else
                r = m - 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp = nums;
        sort(nums.begin(), nums.end());
        int idx, idx2, n = nums.size(), i;
        for (idx = 0; idx < n - 1; ++idx) {
            idx2 = find(nums, idx + 1, n - 1, target - nums[idx]);
            if (idx2 > 0) 
                break;
        }
        for (i = 0; i < n; ++i) {
            if (tmp[i] == nums[idx]) {
                idx = i;
                break;
            }
        }
        for (i = 0; i < n; ++i) {
            if (tmp[i] == nums[idx2] && i != idx) {
                idx2 = i;
                break;
            }
        }        
        return vector<int> {idx, idx2};
    }
};