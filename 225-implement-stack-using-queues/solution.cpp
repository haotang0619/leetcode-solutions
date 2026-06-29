class MyStack {
public:
    int mode = 0, last = 0;
    queue<int> q1, q2;

    MyStack() {}

    int swap(queue<int>& qf, queue<int>& qt) {
        int front, newLast = 0;
        while(!qf.empty()) {
            front = qf.front();
            qf.pop();
            if(!qf.empty()) {
                newLast = front;
                qt.push(front);
            }
        }
        last = newLast;
        return front;
    }
    
    void push(int x) {
        if(mode == 0) q1.push(x);
        else q2.push(x);
        last = x;
    }
    
    int pop() {
        int res = mode == 0 ? swap(q1, q2) : swap(q2, q1);
        mode = 1 - mode;
        return res;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return q1.size() + q2.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
