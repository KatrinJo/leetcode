/*
进阶是使用O(n)的空间
*/
class Solution {
public:
	void swap(vector<int>& nums, int l, int r) {
		int tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
	}
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)
			return;
		sort(nums.begin(), nums.end());

		vector<int> tmps = nums;
		for (int i = 0; i < n; i += 2) {
			nums[i] = tmps[int((n - 1) / 2) - int(i / 2)];
		}
		for (int i = 1; i < n; i += 2) {
			nums[i] = tmps[n - 1 - int(i / 2)];
		}
	}
};
