class MyCircularDeque {
public:
    int idx1 = 0, idx2 = 0;
    vector<int> deq;

    MyCircularDeque(int k) {
        deq.resize(k, -1);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        idx1 = (idx1 - 1 + deq.size()) % deq.size();
        deq[idx1] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        deq[idx2] = value;
        idx2 = (idx2 + 1) % deq.size();
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        deq[idx1] = -1;
        idx1 = (idx1 + 1) % deq.size();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        idx2 = (idx2 - 1 + deq.size()) % deq.size();
        deq[idx2] = -1;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : deq[idx1];
    }
    
    int getRear() {
        return isEmpty() ? -1 : deq[(idx2 - 1 + deq.size()) % deq.size()];
    }
    
    bool isEmpty() {
        return idx1 == idx2 && deq[0] == -1;
    }
    
    bool isFull() {
        return idx1 == idx2 && deq[0] != -1;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
