// 其实不会……主要是边界处理理不太清。这个解法比较干脆利落。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int msize = nums1.size(), nsize = nums2.size();
        if (msize > nsize)
            return findMedianSortedArrays(nums2, nums1);
        
        int val[2][2] = {0};
        int l = 0, r = 2 * msize, m1, m2;

        while(l <= r) {
            m1 = (l + r) / 2;
            m2 = msize + nsize - m1;

            val[0][0] = m1 == 0 ? INT_MIN : nums1[(m1 - 1) / 2]; // left min in nums1
            val[0][1] = m1 == 2 * msize ? INT_MAX : nums1[m1 / 2]; // right max in nums1
            val[1][0] = m2 == 0 ? INT_MIN : nums2[(m2 - 1) / 2];
            val[1][1] = m2 == 2 * nsize ? INT_MAX : nums2[m2 / 2];

            if (val[0][0] > val[1][1])
                r = m1 - 1;
            else if (val[1][0] > val[0][1]) 
                l = m1 + 1;
            else
                break;
        }

        cout << val[0][0] << " " << val[1][0] << " " << val[0][1] << " " << val[1][1] << endl;
        return (max(val[0][0], val[1][0]) + min(val[0][1], val[1][1])) / 2.0;
    }
};