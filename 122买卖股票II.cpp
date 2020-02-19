// 反而变复杂了……
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) 
            return 0;
        
        int with = - prices[0], without = 0;
        int tmp;
        for (int i = 1; i < n; ++i) {
            tmp = with;
            with = max(with, without - prices[i]);
            without = max(without, tmp + prices[i]);
        }

        return without;
        
    }
};

// 简而言之就是把所有上升线段加和
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) 
            return 0;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i)
            sum +=  max(0, prices[i + 1] -  prices[i]);
        return sum;  
    }
};