// 居然是用桶排……有趣
class Solution {
public:
	int maxRes(vector<int>& nums, int bit) {
		if (nums.size() < 2)
			return 0;
		if (bit == 0) {
			int n = nums[0];
			for (auto & num : nums) {
				if (n != num)
					return 1;
			}
			return 0;
		}
		vector<int> zeros, ones;
		int numMinInOnes = -1, numMaxInZeros = -1;
		for (auto & num : nums) {
			if ((num >> (bit - 1)) & 1) {
				if (numMinInOnes < 0) 
					numMinInOnes = num;
				numMinInOnes = min(numMinInOnes, num);
				ones.push_back(num);
			}
			else {
				numMaxInZeros = max(numMaxInZeros, num);
				zeros.push_back(num);
			}
		}
		int res = max(maxRes(zeros, bit - 1), maxRes(ones, bit - 1));
		if (numMinInOnes >= 0 && numMaxInZeros >= 0) 
			res = max(res, (numMinInOnes - numMaxInZeros));
		return res;
	}

	int maximumGap(vector<int>& nums) {
		return maxRes(nums, 30);
	}
};