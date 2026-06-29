class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int now = 0;
        for(auto& t : trips) {
            while(!pq.empty() && pq.top().first <= t[1]) {
                now -= pq.top().second;
                pq.pop();
            }
            now += t[0];
            if(now > capacity) return false;
            pq.push({t[2], t[0]});
        }
        return true;
    }
};
