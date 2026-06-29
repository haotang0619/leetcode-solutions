class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> e(n);
        for(auto& x : edges) {
            e[x[0]].push_back({x[1], x[2]});
            e[x[1]].push_back({x[0], 2 * x[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(dist[u] > d) continue;
            for(auto& [v, d1] : e[u]) {
                if(d + d1 >= dist[v]) continue;
                dist[v] = d + d1;
                pq.push({dist[v], v});
            }
        }
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
