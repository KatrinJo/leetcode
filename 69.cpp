class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int l = 1, r = 1 << 16, m;
        r = x;
        int t1, t2;
        while(l < r) {
            m = (r >> 1) + ((l + (r % 2)) >> 1);
            if (m > INT_MAX / m) {
                r = m - 1;
                continue;
            }
            if ((m + 1) > INT_MAX / (m + 1)) {
                r = m;
                continue;
            }
            t1 = m * m;
            t2 = (m + 1) * (m + 1);
            if (t1 > x)
                r = m - 1;
            else if (t2 > x)
                return m;
            else if (t2 == x)
                return m + 1;
            else
                l = m + 1;
        }
        m = (l + r) >> 1;
        if (m * m > x)
            return m - 1;
        return m;
    }
};