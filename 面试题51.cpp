// 归并排序 千万别vector<int> nums2 = nums 了......

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return calc(nums, 0, n - 1);
    }

    int calc(vector<int> & nums, int left, int right) {
        if (left >= right - 1) {
            if (left < right && nums[left] > nums[right]) {
                int tmp = nums[left];
                swap(nums, left, right);
                return 1;
            }
            return 0;
        }
        int med = (left + right) / 2;
        int res = calc(nums, left, med) + calc(nums, med + 1, right);
        int i = left, j = med + 1;
        vector<int> nums2(right - left + 1, 0);
        for (int i = left; i <= right; ++i)
            nums2[i - left] = nums[i];

        while(i <= med && j <= right) {
            if (nums2[i - left] <= nums2[j - left]) {
                nums[i + j - med - 1] = nums2[i - left];
                ++i;
            } 
            else {
                res += (med - i + 1);
                nums[i + j - med - 1] = nums2[j - left];
                ++j;
            }
        }
        while(i <= med) {
            nums[i + j - med - 1] = nums2[i - left];
            ++i;
        }
        while(j <= right) {
            nums[i + j - med - 1] = nums2[j - left];
            ++j;
        }
        return res;
    }

    void swap(vector<int> & nums, int pos1, int pos2) {
        int tmp;
        tmp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = tmp; 
    }
};