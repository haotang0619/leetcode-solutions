class SummaryRanges {
public:
    multiset<int> st;

    SummaryRanges() {}
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(st.size() == 0) return {};
        vector<vector<int>> ans;
        vector<int> curr = {*st.begin(), *st.begin()};
        for(auto& num : st) {
            if(num > curr[1] + 1) {
                ans.push_back(curr);
                curr = {num, num};
            } else curr = {curr[0], num};
        }
        ans.push_back(curr);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
