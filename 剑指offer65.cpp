// 直接copy了……
class Solution {
public:
    int add(int a, int b) {
        int x = ~(1 << 31);
        while(b != 0) {
            int c = (a & b & x) << 1; // a + b 产生的进位
            a ^= b; // 不算进位的“和”
            b = c;
        }
        return a;
    }
};
