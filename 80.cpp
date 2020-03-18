class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int curr = 1, i, n = nums.size();
        for (i = 2; i < n; ++i) {
            if (nums[i] != nums[curr]) 
                nums[++curr] = nums[i];
            else if (nums[i] != nums[curr - 1])
                nums[++curr] = nums[i];
        }
        return curr + 1;
    }
};


int lowbit1(int n) {
    int cnt = 0;
    while(n) {
        n = n & (n - 1);
        ++cnt;
    }
    return cnt;
}

int lowbit2(int n) {
    return n & (-n);
}