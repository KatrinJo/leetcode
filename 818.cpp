// 还是不熟悉……

class Solution {
public:
    int dp[10001];
    int getn(int num) {
        if (num == 0) return {};
        int n = 0;
        for (n = 1; n < 16; ++n) {
            if (num <= ((1 << n) - 1)) break;
        }
        return n;
    }
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        if (target == 1) {
            dp[target] = 1;
            return 1;
        } 
        int bitnum = getn(target);
        if (target == ((1 << bitnum) - 1)) {
            dp[target] = bitnum;
            return bitnum;
        }
        dp[target] = bitnum + 1 + racecar((1 << bitnum) - 1 - target);
        for (int i = 0; i < bitnum; ++i) {
            dp[target] = min(dp[target], bitnum + i + 1 + racecar(target - (1 << (bitnum - 1)) + (1 << i)));
        }
        return dp[target];
    }
};