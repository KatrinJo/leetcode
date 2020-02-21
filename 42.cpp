// 接雨水。找一段中的最高点，分治。

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2)
            return 0;
        return sumcnt(height, 0, n - 1);
    }

    int sumcnt(vector<int>& height, int l, int r) {
        if (l >= r - 1)
            return 0;
        int maxh = -1, maxhidx = -1, i, res = 0;

        for (i = l + 1; i < r; ++i) 
            if (height[i] > maxh) {
                maxh = height[i];
                maxhidx = i;
            }

        if (height[l] >= maxh && height[r] >= maxh) {
            maxh = min(height[l], height[r]);
            for (i = l + 1; i < r; ++i)
                res += (maxh - height[i]);
        }
        else if (height[r] >= maxh) {
            for (i = maxhidx + 1; i < r; ++i)
                res += (maxh - height[i]);
            res += sumcnt(height, l, maxhidx);
        }
        else if (height[l] >= maxh) {
            for (i = l + 1; i < maxhidx; ++i)
                res += (maxh - height[i]);
            res += sumcnt(height, maxhidx, r);
        }
        else 
            res = sumcnt(height, l, maxhidx) + sumcnt(height, maxhidx, r);
        return res;
    }
};