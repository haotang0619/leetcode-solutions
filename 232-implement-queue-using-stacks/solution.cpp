class MyQueue {
public:
    stack<int> sk1, sk2;
    int mode = 0; // 0: Push, 1: Pop

    MyQueue() {}
    
    void push(int x) {
        if(mode == 1) {
            while(!sk2.empty()) sk1.push(sk2.top()), sk2.pop();
        }
        sk1.push(x);
        mode = 0;
    }
    
    int pop() {
        if(mode == 0) {
            while(!sk1.empty()) sk2.push(sk1.top()), sk1.pop();
        }
        int top = sk2.top();
        sk2.pop();
        mode = 1;
        return top;
    }
    
    int peek() {
        if(mode == 0) {
            while(!sk1.empty()) sk2.push(sk1.top()), sk1.pop();
        }
        mode = 1;
        return sk2.top();
    }
    
    bool empty() {
        return sk1.size() + sk2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
