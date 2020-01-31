// 合并区间。贪心，小区间按左端排序。注意一下lambda表达式写法。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        if (n == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int> &a, const vector<int> &b) { 
                if (a[0] == b[0]) return a[1] < b[1];
                else return a[0] < b[0];
            });
        vector<int> tmp = intervals[0];
        for (auto & x : intervals) {
            if (x[0] <= tmp[1]) {
                if (x[1] > tmp[1])
                    tmp[1] = x[1];
            }
            else {
                res.push_back(tmp);
                tmp[0] = x[0];
                tmp[1] = x[1];
            }
        }
        res.push_back(tmp);

        return res;
    }
};
