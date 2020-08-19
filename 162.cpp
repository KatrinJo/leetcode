class Solution {
public:
	int findpeak(vector<int> & nums, int l, int r) {
        if (l == r) return l;
        if (l == r - 1) return nums[l] > nums[r] ? l : r;
		int m = (l + r) >> 1;
		if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) return m;
		else if (nums[m - 1] < nums[m])
			return findpeak(nums, m, r);
		else 
			return findpeak(nums, l, m);
	}
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		return findpeak(nums, 0, n - 1);
	}
};