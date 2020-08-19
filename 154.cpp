class Solution {
public:
    int findMM(vector<int> & nums, int l, int r) {
        if (l > r)
            return INT_MAX;
        if (l == r || nums[l] < nums[r])
            return nums[l];
        if (l + 1 == r)
            return nums[r];
        int m = (l + r) >> 1;
        return min(findMM(nums, l, m), findMM(nums, m + 1, r));
    }

    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        return findMM(nums, 0, nums.size() - 1);
    }
};