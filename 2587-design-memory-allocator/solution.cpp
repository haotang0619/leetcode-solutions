class Allocator {
public:
    int sz;
    map<int, int> allocations; // [pos, size]
    multimap<int, int> mp; // [id, pos]

    Allocator(int n) {
        sz = n;
    }
    
    int allocate(int size, int mID) {
        int prev = 0;
        for(auto& [pos, size1] : allocations) {
            if(pos - prev >= size) {
                mp.insert({mID, prev});
                allocations[prev] = size;
                return prev;
            }
            prev = pos + size1;
        }
        if(sz - prev >= size) {
            mp.insert({mID, prev});
            allocations[prev] = size;
            return prev;
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        auto range = mp.equal_range(mID);
        int ans = 0;
        for(auto it = range.first; it != range.second; it++) {
            auto& [id, pos] = *it;
            ans += allocations[pos];
            allocations.erase(pos);
        }
        mp.erase(mID);
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
