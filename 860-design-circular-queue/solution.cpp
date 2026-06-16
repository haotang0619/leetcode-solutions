class MyCircularQueue {
public:
    vector<int> qu;
    int head = 0, end = 0, size = 0;
    
    MyCircularQueue(int k) {
        qu.resize(k);    
    }
    
    bool enQueue(int value) {
        if(size == qu.size()) return false;
        qu[end] = value;
        end = (end + 1) % qu.size();
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        head = (head + 1) % qu.size();
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return qu[head];
    }
    
    int Rear() {
        if(size == 0) return -1;
        return qu[(end - 1 + qu.size()) % qu.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == qu.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
