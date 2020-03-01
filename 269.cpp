// 拓扑排序……对我来说有点难了……一下子没有想到

class Solution {
private:
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */

    string alienOrder(vector<string> &words) {
        // Write your code here
        int n = words.size();
        if (n == 0) return "";
        
        vector<vector<int>> edge (26, vector<int>(26, -1));
        vector<int> in(26, -1), order(26, 0);
        int nOrder = 1;
        
        for (auto & w : words) {
            for (auto & c : w) {
                if (in[c - 'a'] == -1)
                    in[c - 'a'] = 0;
                
                if (order[c - 'a'] == 0) {
                    order[c - 'a'] = nOrder;
                    ++nOrder;
                }
            }
        }
 
        int minl, i, j;
        for (i = 0; i < n - 1; ++i) {
            minl = min(words[i].length(), words[i + 1].length());
            for (j = 0; j < minl; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    edge[words[i][j] - 'a'][words[i + 1][j] - 'a'] = 1;
                    ++in[words[i + 1][j] - 'a'];
                    break;
                }
                if (j == minl && words[i].length() > words[i + 1].length()) return "";
            }
        }
        
        string res;
        int cnt = 0;
        priority_queue<char, vector<char>, greater<char>> myque;
        
        for (int i = 0; i < 26; ++i) {
            if (in[i] == 0)
                myque.push('a' + i);
            if (in[i] >= 0) ++cnt;
        }
        
        char c;
        while (!myque.empty()) {
            c = myque.top(); 
            myque.pop();
            res.push_back(c);
            for (int j = 0; j < 26; ++j) {
                if (edge[c - 'a'][j] != -1) {
                    --in[j];
                    if (in[j] == 0) 
                        myque.push('a' + j);
                }
            }
        }
        if (res.length() == cnt)
            return res;
        return "";
    }
};