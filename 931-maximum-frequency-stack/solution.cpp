class FreqStack {
public:
    int idx = 0;
    unordered_map<int, vector<int>> mp; // <val, idx>
    vector<set<pair<int, int>>> freq; // <times, <idx, val>>
    set<int> st; // times

    FreqStack() {
        freq.push_back({});
    }
    
    void push(int val) {
        if(mp.find(val) == mp.end()) mp[val] = {};
        int oldFreq = mp[val].size();
        int newFreq = oldFreq + 1;
        if(oldFreq >= 1) {
            int lastIdx = mp[val].back();
            freq[oldFreq].erase({lastIdx, val});
            if(freq[oldFreq].size() == 0) st.erase(oldFreq);
        }
        mp[val].push_back(idx);
        if(freq.size() < newFreq + 1) freq.push_back({});
        freq[newFreq].insert({idx, val});
        if(freq[newFreq].size() == 1) st.insert(newFreq);
        idx++;
    }
    
    int pop() {
        int oldFreq = *(st.rbegin());
        int newFreq = oldFreq - 1;
        auto [idx, val] = *(freq[oldFreq].rbegin());
        freq[oldFreq].erase({idx, val});
        if(freq[oldFreq].size() == 0) st.erase(oldFreq);
        mp[val].pop_back();
        if(newFreq > 0) {
            freq[newFreq].insert({mp[val].back(), val});
            if(freq[newFreq].size() == 1) st.insert(newFreq);
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
