class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int l = 0, r = nums.size() - 1, m = 0;
        while(l <= r) {
            if (nums[l] <= nums[r]) {
                return nums[l];
            }
            m = (l + r) / 2;
            if (nums[m] >= nums[l]) {
                l = m + 1;
            }
            else 
                r = m;
        }
        return nums[m];
    }
};