class Solution {
public:
    struct Freq{
        int num;
        int cnt;
        Freq(int _n = -1, int _c = 0) {
            num = _n;
            cnt = _c;
        }
        bool operator < (const Freq & b) {
            return cnt > b.cnt;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        for (auto n : nums) 
            mymap[n]++;
        vector<Freq> myvec;
        for (auto p: mymap) 
            myvec.push_back(Freq(p.first, p.second));
        sort(myvec.begin(), myvec.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(myvec[i].num);
        }        
        return res;
    }
};