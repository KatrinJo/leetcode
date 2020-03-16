class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) return;
        int n = nums.size();
        int i = 0, j = n - 1, curr = 0;
        while(curr <= j) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[i]);
                ++i;
                ++curr;
            }
            else if (nums[curr] == 2) {
                swap(nums[curr], nums[j]);
                --j;
            }
            else {
                ++curr;
            }
        }
    }
};