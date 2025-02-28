class MinStack {
public:
    stack<int> sk1;
    stack<int> sk2;

    MinStack() {
        
    }
    
    void push(int val) {
        sk1.push(val);
        if(sk2.empty()) sk2.push(val);
        else sk2.push(min(val, sk2.top()));
    }
    
    void pop() {
        sk1.pop();
        sk2.pop();
    }
    
    int top() {
        return sk1.top();
    }
    
    int getMin() {
        return sk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
