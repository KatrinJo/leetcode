class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> real, help;
    MinStack() {
        while(!real.empty())
            real.pop();
        while(!help.empty())
            help.pop();
    }
    
    void push(int x) {
        real.push(x);
        if (!help.empty()) {
            x = min(x, help.top());
        }
        help.push(x);
    }
    
    void pop() {
        real.pop();
        help.pop();
    }
    
    int top() {
        return real.top();
    }
    
    int getMin() {
        return help.top();        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */