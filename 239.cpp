// 莫名其妙就过了……但是效率很低

class Solution {

public:

    void del(map<int, int> & m, int num) {
        if (m[num] == 1)
            m.erase(num);
        else if (m[num] > 1)
            m[num] -= 1;
        else
            cout << "noway" << endl;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i;
        if (n < k || n == 0) return {};
        vector<int> res;
        map<int, int> myque;
        for (i = 0; i < k; ++i)
            myque[nums[i]] += 1;
        
        auto it = myque.rbegin();
        res.push_back(it->first);
        del(myque, nums[0]);

        for (; i < n; ++i) {
            myque[nums[i]] += 1;
            it = myque.rbegin();
            res.push_back(it->first);
            del(myque, nums[i - k + 1]);
        
        }
        return res;
    }
};

// 看题解，dp做法很有趣
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k || n == 0) return {};
        vector<int> res;
        vector<int> left(n), right(n);
        int i, maxv;
        for (i = 0; i < n; ++i) {
            if (i % k == 0)
                maxv = nums[i];
            maxv = max(nums[i], maxv);
            left[i] = maxv;
        }
        for (i = n - 1; i >= 0; --i) {
            if ((i == n - 1) || ((i + 1) % k == 0)) 
                maxv = nums[i];
            maxv = max(nums[i], maxv);
            right[i] = maxv;
        }
        for (i = 0; i <= n - k; ++i) {
            res.push_back(max(right[i], left[i + k - 1]));
        }
        
        return res;
    }
};