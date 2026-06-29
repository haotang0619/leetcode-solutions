// Saw all hints
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int n) {
        vector<long long> minOfLaps = {0};
        priority_queue<tuple<long long, long long, long long, int>, vector<tuple<long long, long long, long long, int>>, greater<>> pq; // [time, f, r, lap]
        for(auto&t : tires) pq.push({t[0], t[0], t[1], 1});
        while(!pq.empty() && minOfLaps.size() <= n) {
            auto [t, f, r, lap] = pq.top();
            pq.pop();
            if(lap == minOfLaps.size()) minOfLaps.push_back(t);
            while(lap < minOfLaps.size() && f * r <= INT_MAX) f *= r, t += f, lap++;
            if(lap != minOfLaps.size()) continue;
            pq.push({t, f, r, lap});
        }
        
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(minOfLaps.size() <= i - j) continue;
                dp[i] = min(dp[i], dp[j] + minOfLaps[i - j] + (j > 0 ? changeTime : 0));
            }
        }
        return dp[n];
    }
};
