class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		auto num = digits.size();
		bool flag = true;
		for (int i = num - 1; i >= 0; i--) {
			if (flag) {
				flag = false;
				if (digits[i] == 9) {
					digits[i] = 0;
					flag = true;
				}
			}
			else
				return digits;
		}
		if (flag) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};
