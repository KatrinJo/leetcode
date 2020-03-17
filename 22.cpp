class Solution {
public:

    void gen(vector<string> & res, string & tmp, int numleft, int numright, int n) {
        
        if (numleft < numright || numleft > n) 
            return;
        if (numleft == numright && numleft == n) {
            res.push_back(tmp);
        }
        else if (numleft == numright) {
            tmp.push_back('(');
            gen(res, tmp, numleft + 1, numright, n);
            tmp.pop_back();
        }
        else {
            tmp.push_back('(');
            gen(res, tmp, numleft + 1, numright, n);
            tmp.back() = ')';
            gen(res, tmp, numleft, numright + 1, n);
            tmp.pop_back();            
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<string> res;
        string tmp = "(";
        gen(res, tmp, 1, 0, n);
        return res;

    }
};