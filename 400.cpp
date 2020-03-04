class Solution {
public:
    int findNthDigit(int n) {
        // 1~9:9 * 1
        // 10~99:90 *  2
        // 100~999:900 * 3
        // 1000~9999:9000 * 4
        long long int k = 1, num = 0, start = 1, tmp, i;
        while(true) {
            tmp = num + k * 9 * start;
            if (tmp == n) return 9;
            else if (tmp > n) break;
            num = tmp;
            start *= 10;
            ++k;
        }
        tmp = (n - num - 1) / k;
        start += tmp;
        num += k * tmp;
        if (num == n) return start % 10;
        for (i = 0; i < k - (n - num); ++i)
            start /= 10;
        return start % 10;
    }
};