class MinStack {
    stack<int> _stack;
    stack<int> min;
public:
    MinStack() {
    }
    
    void push(int val) {
        _stack.push(val);
        if (min.empty() || val <= min.top())
            min.push(val);
    }
    
    void pop() {
        if (min.top() == _stack.top())
            min.pop();
        _stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return min.top();
    }
};
