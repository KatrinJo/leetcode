
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        char c;
        if (s.length() % 2) return false;
        for (auto & x : s) {
            if (x == '(' || x == '[' || x == '{' )
                mystack.push(x);
            else {
                if (mystack.empty()) return false;
                c = mystack.top();
                mystack.pop();
                if ((c == '(' && x == ')') || 
                    (c == '[' && x == ']') || 
                    (c == '{' && x == '}'))
                    continue;
                return false;
            }
        }
        return mystack.empty();
    }
};