class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0)
            return -1;
        int sum = 0, tmp;
        vector<int> sub;
        for (int i = 0; i < gas.size(); ++i) {
            tmp = gas[i] - cost[i];
            sub.push_back(tmp);
            sum += tmp;
        }
        if (sum < 0)
            return -1;
        
        for (int i = 0; i < gas.size(); ++i) {
            if (sub[i] < 0) continue;
            tmp = (i + 1) % gas.size();
            sum = sub[i];
            while(sum >= 0) {
                if (tmp == i)
                    return i;
                sum += sub[tmp];
                tmp = (tmp + 1) % gas.size();
            }
            if (tmp < i)
                return -1;
        }

        return -1;
    }
};