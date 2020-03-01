class Solution {
public:
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
    
    bool dfs(string & s, unordered_map<string, bool> & mymap) {
        if (mymap.count(s))
            return mymap[s];
        int l = s.length(); 
        for (int i = 0; i < l - 1; ++i) {
            if (s[i] != s[i + 1]) continue;
            if (s[i] != '+') continue;
            s[i] = s[i + 1] = '-';
            if (!dfs(s, mymap)) {
                s[i] = s[i + 1] = '+';  
                mymap[s] = true;
                return true;
            }
            s[i] = s[i + 1] = '+';           
        }
        mymap[s] = false;
        return false;
    }
    
    bool canWin(string &s) {
        int n = s.length();
        if (n <= 1) return false;
        
        unordered_map<string, bool> mymap;
        
        return dfs(s, mymap);
    }
};