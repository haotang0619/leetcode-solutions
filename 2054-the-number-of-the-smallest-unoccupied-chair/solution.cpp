class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        for(int i = 0; i < n; i++) {
            times[i].push_back(i);
            pq1.push(i);
        }
        sort(times.begin(), times.end());
        for(auto &x : times) {
            while(!pq2.empty() && pq2.top().first <= x[0]) {
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            int pos = pq1.top();
            if(x[2] == targetFriend) return pos;
            pq1.pop();
            pq2.push({x[1], pos});
        }
        return 0;
    }
};
