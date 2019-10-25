class Solution {
public:
	/*
	* @param nums: A list of integers
	* @return: nothing
	*/
	void wiggleSort(vector<int> &nums) {
		int n = nums.size(), tmp;
		if (n == 0)
			return;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				// 局部极小值
				if (i - 1 > 0) {
					if (nums[i - 1] < nums[i]) {
						tmp = nums[i - 1];
						nums[i - 1] = nums[i];
						nums[i] = tmp;
					}
				}
				if (i + 1 < n) {
					if (nums[i + 1] < nums[i]) {
						tmp = nums[i + 1];
						nums[i + 1] = nums[i];
						nums[i] = tmp;
					}
				}
			}
			else {
				// 局部极大值
				if (nums[i - 1] > nums[i]) {
					tmp = nums[i - 1];
					nums[i - 1] = nums[i];
					nums[i] = tmp;
				}
				if (i + 1 < n) {
					if (nums[i + 1] > nums[i]) {
						tmp = nums[i + 1];
						nums[i + 1] = nums[i];
						nums[i] = tmp;
					}
				}
			}
		}
	}
};
