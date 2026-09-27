class MyCalendar {
public:
    set<pair<int, int>> st;

    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        auto it = st.lower_bound({startTime, startTime});
        if(it != st.begin()) it--;
        while(it != st.end()) {
            auto& [l, r] = *it;
            if(l >= endTime) break;
            int mxl = max(l, startTime), mnr = min(r, endTime);
            if(mxl < mnr) return false;
            it++;
        }
        st.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
