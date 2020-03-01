// 惭愧用了最初级的办法……可以看一下leetcode的解法

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return vector<int>{0};
        vector<int> arr{nums[n - 1]}, res{0};
        int i, j, tmp;
        for (i = n - 2; i >= 0; --i) {
            arr.push_back(nums[i]);
            for (j = n - i - 1; j > 0; --j) {
                if (arr[j] <= arr[j - 1]) {
                    tmp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = tmp;
                }
                else
                    break;
            }
            res.push_back(j);       
        }
        reverse(res.begin(), res.end());
        return res;
    }
};