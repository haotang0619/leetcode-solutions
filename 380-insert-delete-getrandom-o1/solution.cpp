class RandomizedSet {
public:
    mt19937 engine{random_device{}()};
    unordered_map<int, int> mp;
    vector<int> v;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.contains(val)) return false;
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.contains(val)) return false;
        int idx = mp[val];
        if(idx != v.size() - 1) {
            v[idx] = v.back();
            mp[v.back()] = idx;
        }
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        uniform_int_distribution<> dist(0, n - 1);
        int idx = dist(engine);
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
