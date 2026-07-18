class AllOne {
public:
    unordered_map<string, int> mp1;
    map<int, unordered_set<string>> mp2;

    AllOne() {}
    
    void inc(string key) {
        int& cnt = mp1[key];
        mp2[cnt].erase(key);
        if(mp2[cnt].size() == 0) mp2.erase(cnt);
        cnt++;
        mp2[cnt].insert(key);
    }
    
    void dec(string key) {
        int& cnt = mp1[key];
        mp2[cnt].erase(key);
        if(mp2[cnt].size() == 0) mp2.erase(cnt);
        cnt--;
        if(cnt > 0) mp2[cnt].insert(key);
        else mp1.erase(key);
    }
    
    string getMaxKey() {
        if(mp2.size() == 0) return "";
        return *(prev(mp2.end()))->second.begin();
    }
    
    string getMinKey() {
        if(mp2.size() == 0) return "";
        return *(mp2.begin())->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
