// 也可以异或

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        long long int s = accumulate(nums.begin(), nums.end(), 0);
        long long int sum = n * (n + 1) / 2;
        return sum - s;
    }
};