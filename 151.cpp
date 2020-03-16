class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int start = 0, end = 0;
        string res;
        while(start < s.length()) {
            end = s.find(" ", start);
            if (end == start) 
                ++start;
            else {
                res = s.substr(start, end - start) + " " + res;
                start = end + 1;
            }
        }
        res.pop_back();
        return res;
    }
};