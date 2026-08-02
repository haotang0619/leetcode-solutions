class MyCircularQueue {
public:
    vector<int> v;
    int i = 0, j = 0, k;
    
    MyCircularQueue(int K) {
        k = K;
        v.resize(k + 1);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        v[j] = value;
        j = (j + 1) % (k + 1);
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        i = (i + 1) % (k + 1);
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[i];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[(j + k) % (k + 1)];
    }
    
    bool isEmpty() {
        return i == j;
    }
    
    bool isFull() {
        return ((j + 1) % (k + 1)) == i;
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
