class MyCalendarThree {
public:
    vector<pair<int, int>> v;

    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        v.push_back({startTime, endTime});
        sort(v.begin(), v.end());
        int ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto& [l, r] : v) {
            while(!pq.empty() && pq.top() <= l) pq.pop();
            pq.push(r);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
