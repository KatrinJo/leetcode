class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            if (nums[i - 1] == nums[i])
                return nums[i - 1];
        return nums[0];
    }
};