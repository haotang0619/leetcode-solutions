class RangeModule {
public:
    set<pair<int, int>> st;

    RangeModule() {}

    void check() {
        for(auto& [l, r] : st) cout << l << " " << r << endl;
        cout << endl;
    }
    
    void addRange(int left, int right) {
        auto it = st.upper_bound({right, INT_MAX});
        if(it == st.begin()) {
            st.insert({left, right});
            return;
        }
        it = prev(it);
        pair<int, int> curr = {left, right};
        vector<pair<int, int>> cut;
        while(true) {
            if((*it).second >= curr.first) {
                curr.first = min(curr.first, (*it).first);
                curr.second = max(curr.second, (*it).second);
                cut.push_back(*it);
                if(it == st.begin()) break;
                it = prev(it);
            } else break;
        }
        for(auto& range : cut) st.erase(range);
        st.insert(curr);
    }
    
    bool queryRange(int left, int right) {
        // check();
        auto it = st.upper_bound({right, right});
        if(it == st.begin()) return false;
        it = prev(it);
        auto& [l, r] = *it;
        return l <= left && r >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = st.upper_bound({right, INT_MAX});
        if(it == st.begin()) return;
        it = prev(it);
        vector<pair<int, int>> add, cut;
        while(true) {
            if((*it).second <= left) break;
            if((*it).second > right) add.push_back({right, (*it).second});
            if((*it).first < left) add.push_back({(*it).first, left});
            cut.push_back(*it);
            if(it == st.begin()) break;
            it = prev(it);
        }
        for(auto& range : cut) st.erase(range);
        for(auto& range : add) st.insert(range);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
