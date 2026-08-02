class RandomizedCollection {
public:
    mt19937 engine{random_device{}()};
    unordered_multimap<int, int> mp;
    vector<int> v;
    
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool notExist = !mp.contains(val);
        mp.insert({val, v.size()});
        v.push_back(val);
        return notExist;
    }
    
    bool remove(int val) {
        if(!mp.contains(val)) return false;
        auto valIt = mp.find(val);
        auto [tmp, idx] = *valIt;
        if(idx != v.size() - 1) {
            v[idx] = v.back();
            auto range = mp.equal_range(v.back());
            for(auto it = range.first; it != range.second; it++) {
                if(it->second == v.size() - 1) {
                    mp.erase(it);
                    break;
                }
            }
            mp.insert({v.back(), idx});
        }
        v.pop_back();
        mp.erase(valIt);
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
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
