class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
        int n = s.length();
        if (n <= 1) return true;
        vector<int> m(26, 0);
        for (int i = 0; i < n; ++i) {
            m[s[i]-'a'] += 1;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            cnt += m[i] % 2;
        }
        return cnt <= 1;
        /*
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i)
            m[s[i]] += 1;
        int cnt = 0;
        for (auto & x : m) 
            cnt += (x.second % 2);
        return cnt <= 1;
        */
    }
};