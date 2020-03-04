// map是有序的 但真正的做法是用并查集……
// 并查集做法：用unorder_map，每加入一个元素，就通过并查集找到它最左边的数字记为father。
// 到x为止的最大连续序列长度x-father(x)+1，取最大值即可。

class Solution {
map<int, int> mymap;
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = 0, bef, tmpres = 0;
        bool flag = false;
        for (auto & x : nums)
            mymap[x] = 1;

        for (auto & x : mymap) {
            if (!flag) {
                flag = true;
                tmpres = 0;
            }
            else {
                if (x.first != bef + 1) {
                    res = max(res, tmpres);
                    tmpres = 0;
                }
            }
            bef = x.first;
            ++tmpres;
        }
        res = max(res, tmpres);
        return res;
    }
};


// 记录一个超级dp解法……
// 作者：izeuwy
// 链接：https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/c-dong-tai-gui-hua-fu-za-du-on-by-izeuwy/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int ret = 0;
        for(auto &x : nums) {
            if(!dp[x]) dp[x - dp[x - 1]] = dp[x + dp[x + 1]] = dp[x] = dp[x - 1] + dp[x + 1] + 1;
            ret = max(ret, dp[x]);
        }
        return ret;
    }
};
