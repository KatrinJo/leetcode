class Solution {
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        // write your code here
        vector<string> vecs(n);
        for (int i = 0; i < n; ++i)
            vecs[i] = to_string(i + 1);
        while(n > 1) {
            for (int i = 0; i < n/2; ++i)
                vecs[i] = "(" + vecs[i] + "," + vecs[n - 1 - i] + ")";
            n /= 2;
        }
        return vecs[0];
        
    }
};