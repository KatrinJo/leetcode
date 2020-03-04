class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, n = arr.size(), i, maxval = -1;
        if (n == 1) return 1;
        for (i = 0; i < n; ++i) {
            maxval = max(maxval, arr[i]);
            if (i == maxval || i == n - 1) {
                ++res;
                ++maxval;
            }
        }
        return res;
    }
};