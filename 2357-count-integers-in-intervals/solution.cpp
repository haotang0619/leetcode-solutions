class CountIntervals {
public:
    int cnt = 0;
    map<int, int> mp;

    CountIntervals() {}
    
    void add(int left, int right) {
        auto it = mp.upper_bound(left);
        pair<int, int> curr = {left, right};
        auto& [l, r] = curr;
        vector<int> removed;
        if(it != mp.begin()) {
            auto& [l1, r1] = *prev(it);
            if(r1 >= l) l = l1, r = max(r, r1), removed.push_back(l1);
        }
        while(it != mp.end()) {
            auto& [l1, r1] = *it;
            if(r >= l1) r = max(r, r1), removed.push_back(l1), it++;
            else break;
        }
        for(auto& x : removed) cnt -= mp[x] - x + 1, mp.erase(x);
        cnt += r - l + 1, mp[l] = r;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
