class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> e(n + 1);
        for(auto &t : times) e[t[0]].push_back({t[1], t[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, d1] : e[u]) {
                if(d + d1 >= dist[v]) continue;
                pq.push({d + d1, v});
                dist[v] = d + d1;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};
