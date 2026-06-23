class MyCalendarTwo {
public:
    vector<pair<int, int>> cal;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(int i = 0; i + 1 < cal.size(); i++) {
            auto [s1, e1] = cal[i];
            for(int j = 1; j <= 2; j++) {
                if(i + j >= cal.size()) break;
                auto [s2, e2] = cal[i + j];
                if(e1 > s2) {
                    int e3 = min(e1, e2);
                    int s4 = min(startTime, s2), e4 = s4 == s2 ? e3 : endTime;
                    int s5 = s4 == s2 ? startTime : s2;
                    if(e4 > s5) return false;
                }
            }
        }
        cal.push_back({startTime, endTime});
        sort(cal.begin(), cal.end());
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
