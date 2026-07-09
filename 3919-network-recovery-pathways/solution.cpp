// Saw 1 hint
class Solution {
public:
    bool dijkstra(vector<vector<pair<int, int>>>& e, int minW, long long k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // [d, u]
        pq.push({0, 0});
        int n = e.size();
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto& [v, d1] : e[u]) {
                if(d1 < minW) continue;
                if(d + d1 > k) continue;
                if(dist[v] <= d + d1) continue;
                dist[v] = d + d1;
                pq.push({dist[v], v});
            }
        }
        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> e(n);
        for(auto& x : edges) {
            if(!online[x[0]] || !online[x[1]]) continue;
            e[x[0]].push_back({x[1], x[2]});
        }
        int l = -1, r = 1e9;
        while(l < r) {
            int m = l + (r - l + 1) / 2;
            if(dijkstra(e, m, k)) l = m;
            else r = m - 1;
        }
        return l;
    }
};
