class Solution {
public:
    vector<vector<int>> dijkstra(vector<vector<pair<int, int>>>& e, int src, int k) {
        int n = e.size();
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        // [d, node, step]
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});
        while(!pq.empty()) {
            // NOTE: don't use references here; pq.pop() will invalidate them.
            auto [d, u, step] = pq.top();
            pq.pop();
            if(d > dist[u][step]) continue;
            if(step >= k + 1) continue;
            for(auto& [v, d1] : e[u]) {
                if(d + d1 >= dist[v][step + 1]) continue;
                dist[v][step + 1] = d + d1;
                pq.push({dist[v][step + 1], v, step + 1});
            }

        }
        return dist;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> e(n);
        for(auto& f : flights) e[f[0]].push_back({f[1], f[2]});
        auto dist = dijkstra(e, src, k);
        int ans = INT_MAX;
        for(int i = 0; i < k + 2; i++) ans = min(ans, dist[dst][i]);
        return ans == INT_MAX ? -1 : ans;
    }
};
