class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 0)
            return {};
        int n = numbers.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if (numbers[l] + numbers[r] > target)
                --r;
            else if (numbers[l] + numbers[r] < target)
                ++l;
            else
                break;
        }
        if (l == r)
            return {};
        return vector<int>{l + 1, r + 1};
    }
};