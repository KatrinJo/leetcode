// 写的有点难看，复杂度是O(n^2)

class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        int i = 0, j = 0, k = 0, sumik = 0;
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        if (n < 3) {
            return 0;
        }
        for (j = 1; j < n-1; ++j) {
            sumik = target - nums[j];
            i = j - 1;
            k = j + 1;
            
            while(i >= 0 && k < n && k >= j) {
                while((k < n) && (nums[i] + nums[k] < sumik)) {
                    k++;
                }
                if (k > j)
                    --k;
                --i;
                res += k-j;
                // cout << j << " " << (k - j) << endl;
            }
        }
        return res;
    }
};
