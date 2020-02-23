// 写得太丑了……

class Solution {
public:
    /**
     * @param nums: a sorted array
     * @param a: 
     * @param b: 
     * @param c: 
     * @return: a sorted array
     */
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        // Write your code here
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return vector<int>{a * nums[0] * nums[0] + b * nums[0] + c};
        if (a == 0) {
            vector<int> res;
            for (auto x : nums) {
                res.push_back(b * x + c);
            }
            if (b < 0)
                reverse(res.begin(), res.end());
            return res;
        }
        double med = - b / (2.0 * a);
        vector<int> res;
        vector<int> f;
        for (auto x : nums) 
            f.push_back(a * x * x + b * x + c);
        
        if ((nums[0] >= med && nums[n - 1] >= med) || (nums[0] <= med && nums[n - 1] <= med)) {
            if (f[0] > f[1])
                reverse(f.begin(), f.end());
            return f;
        }
        int i = 0, j = 0, t = 0;
        while(i < n - 1) {
            if ((nums[i] <= med && nums[i + 1] > med) || (nums[i] >= med && nums[i + 1] < med))
                break;
            ++i;
        }
        t = i;
        if (a > 0) {
            j = i + 1;
            while(i >= 0 && j < n) {
                if (f[i] > f[j]) {
                    res.push_back(f[j]);
                    ++j;
                }
                else if (f[i] == f[j]) {
                    res.push_back(f[j]);
                    ++j;
                    res.push_back(f[i]);
                    --i;
                }
                else {
                    res.push_back(f[i]);
                    --i;
                }
            }
            while(i >= 0) {
                res.push_back(f[i]);
                --i;
            }
            while(j < n) {
                res.push_back(f[j]);
                ++j;
            }
        }
        else {
            i = 0, j = n - 1;
            while(i <= t && j > t) {
                if (f[i] > f[j]) {
                    res.push_back(f[j]);
                    --j;
                }
                else if (f[i] == f[j]) {
                    res.push_back(f[j]);
                    --j;
                    res.push_back(f[i]);
                    ++i;
                }
                else {
                    res.push_back(f[i]);
                    ++i;
                }
            }
            while(i <= t) {
                res.push_back(f[i]);
                ++i;
            }
            while(j > t) {
                res.push_back(f[j]);
                --j;
            }
        }
        
        return res;
    }
};