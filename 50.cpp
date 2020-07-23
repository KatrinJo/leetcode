class Solution {
public:

    double tmp(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n % 2 == 0)
            return tmp(x * x, n / 2);
        return x * tmp(x * x, n / 2);
    }

    double myPow(double x, int n) {
        double t = tmp(x, abs(n));
        if (n < 0)
            return 1.0 / t;
        return t;
    }
};