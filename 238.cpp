class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 0; i < nums.size() - 1; ++i)
            res[i + 1] = res[i] * nums[i];
        int tmp = 1;
        for (int i = nums.size() - 1; i >= 0;--i) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        return res;        
    }
};