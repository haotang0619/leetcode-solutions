class LRUCache {
public:
    int time = 0;
    int cap;
    unordered_map<int, int> cache;
    unordered_map<int, int> timing;
    vector<pair<int, int>> instructions;
    int idx = 0;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        timing[key] = time;
        instructions.push_back({key, time++});
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end() && cache.size() == cap) {
            while(true) {
                int k = instructions[idx].first, t = instructions[idx].second;
                idx++;
                if(cache.find(k) == cache.end() || timing[k] != t) continue;
                cache.erase(k);
                break;
            }
        }
        timing[key] = time;
        instructions.push_back({key, time++});
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
