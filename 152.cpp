
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int maxv = 1, minv= 1, res = nums[0], tmp;
        for (auto & x : nums) {
            tmp = maxv;
            maxv = max(minv * x, max(maxv * x, x));
            minv = min(tmp * x, min(minv * x, x));
            res = max(maxv, res);
        }
        return res;
    }
};