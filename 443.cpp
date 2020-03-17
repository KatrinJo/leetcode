class Solution {
public:
    int compress(vector<char>& chars) {
        char c;
        int i = 0, s = 0, e = 0;
        string str;
        while(e < chars.size()) {
            c = chars[s];
            e = s;
            while(e < chars.size() && chars[e] == chars[s]) 
                ++e;
            chars[i++] = c;
            if (e - s > 1) {
                str = to_string(e - s);
                for (auto ch : str) {
                    chars[i++] = ch;
                }
            }
            s = e;
        }
        s = chars.size() - i;
        while(s--) {
            chars.pop_back();
        }
        return i;
    }
};