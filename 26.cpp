class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int curr = 0, i, n = nums.size();
        for (i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1])
                continue;
            nums[++curr] = nums[i];
        }
        for (i = curr + 1; i < n; ++i)
            nums.pop_back();
        return curr + 1;
    }
};