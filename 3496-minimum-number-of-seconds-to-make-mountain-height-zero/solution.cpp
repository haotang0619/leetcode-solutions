class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        for(auto x : workerTimes) pq.push({x, x, 1});
        long long ans = 0;
        while(mountainHeight--) {
            auto top = pq.top();
            long long now = top[0], base = top[1], time = top[2];
            pq.pop();
            ans = now;
            pq.push({now + base * (time + 1), base, time + 1});
        }
        return ans;
    }
};
