class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        if (n == 1) 
            return vector<string> {to_string(nums[0])};
        vector<string> res;
        int s = nums[0], e = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == e + 1)
                e = nums[i];
            else {
                if (s == e)
                    res.push_back(to_string(e));
                else 
                    res.push_back(to_string(s) + "->" + to_string(e));
                s = e = nums[i];
            }
        }
        if (s == e)
            res.push_back(to_string(e));
        else 
            res.push_back(to_string(s) + "->" + to_string(e));
        return res;        
    }
};