class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;        
        int l = 0, r = nums.size() - 1, m = 0;
        while(l <= r) {
            m = (l + r) / 2;
            if (target == nums[m])
                return m;
            if (nums[m] < nums[l]) {
                if (target > nums[m] && nums[r] >= target)
                    l = m + 1;
                else 
                    r = m - 1;
            }
            else if (nums[m] == nums[l]) {
                l = m + 1;
            }
            else {
                if (target < nums[m] && nums[l] <= target)
                    r = m - 1;
                else
                    l = m + 1;
            }
            
        }
        return -1;
    }
};