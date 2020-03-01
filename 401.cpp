// 不是搞oi出身,对用n&(n-1)计算二进制1的个数不敏感……

class Solution {
private:
    vector<string> hour;
    vector<string> minute;
public:
    void collectH(int n, int start, int rest) {
        if (start > 4 || n > 11) return;
        if (rest == 0) {
            string s = to_string(n);
            hour.push_back(s);
            return;
        }
        for (; start < 4; ++start) 
            collectH(n + (1 << start), start + 1, rest - 1);
    }
    void collectM(int n, int start, int rest) {
        if (start > 6 || n > 59) return;
        if (rest == 0) {
            string s = to_string(n);
            if (n < 10) s = "0" + s;
            minute.push_back(s);
            return;
        }
        for (; start < 6; ++start)
            collectM(n + (1 << start), start + 1, rest - 1);
    }
    vector<string> readBinaryWatch(int num) {
        if (num > 8) return {};
        int minH = max(0, num - 5), maxH = min(3, num);
        int i;
        vector<string> res;
        for (i = minH; i <= maxH; ++i) {
            hour.clear();
            minute.clear();
            collectH(0, 0, i);
            collectM(0, 0, num - i);
            for (auto & h : hour)
                for (auto & m : minute) 
                    res.push_back(h + ":" + m);
        }
        return res;
    }
};