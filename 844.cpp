class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string equS = "", equT = "";
        for (auto & c : S) {
            if (c == '#') {
                if (equS.length() > 0) 
                    equS.pop_back();
            }
            else 
                equS.push_back(c);
        }
        for (auto & c : T) {
            if (c == '#') {
                if (equT.length() > 0) 
                    equT.pop_back();
            }
            else 
                equT.push_back(c);
        }
        return equS == equT;
    }
};