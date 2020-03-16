class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            nums[i] += nums[i - 1];
        int minv = min(0,nums[0]), maxv = nums[0];
        for (int i = 1; i < n; ++i) {
            maxv = max(nums[i] - minv, maxv);
            if (nums[i] < minv) 
                minv = nums[i];
        }
        return maxv;
    }
};