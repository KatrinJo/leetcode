class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i)
            sum[i] = sum[i - 1] + nums[i - 1];
        int cnt = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (sum[i] - sum[j] == k)
                    ++cnt;
            }
        }
        return cnt;
    }
};