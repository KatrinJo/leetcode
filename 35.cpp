class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int l = 0, r = nums.size() - 1, m;
        if (target < nums[l]) return 0;
        if (target > nums[r]) return nums.size();
        while(l < r) {
            m = (l + r) >> 1;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target) 
                l = m + 1;
            else 
                r = m - 1;
        }
        m = (l + r) >> 1;
        if (nums[m] < target)
            return m + 1;
        return m;
    }
};