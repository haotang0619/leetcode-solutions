class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> e(n); // [v, time]
        for(auto& x : edges) e[x[0]].push_back({x[1], x[2]});
        
        vector<vector<long long>> dist(n, vector<long long>(power + 1, LLONG_MAX));
        dist[source][power] = 0;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq; // [time, cost, index]
        pq.push({0, power, source});
        
        while(!pq.empty()) {
            auto [t, c, u] = pq.top();
            pq.pop();
            if(dist[u][c] > t) continue;
            if(u == target) continue;
            for(auto& [v, t1] : e[u]) {
                int c1 = c - cost[u];
                if(c1 < 0) continue;
                if(dist[v][c1] <= t + t1) continue;
                dist[v][c1] = t + t1;
                pq.push({dist[v][c1], c1, v});
            }
        }

        vector<long long> ans = {LLONG_MAX, LLONG_MIN};
        for(int i = power; i >= 0; i--) {
            if(dist[target][i] < ans[0]) ans[0] = dist[target][i], ans[1] = i;
        }
        return ans[0] == LLONG_MAX ? vector<long long>({-1, -1}) : ans;
    }
};
