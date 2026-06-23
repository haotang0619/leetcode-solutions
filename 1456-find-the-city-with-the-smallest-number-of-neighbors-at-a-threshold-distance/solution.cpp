class Solution {
public:
    int dijkstra(int src, int thres, vector<vector<pair<int, int>>>& e) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        int val = 0;
        vector<int> dist(e.size(), INT_MAX);
        dist[src] = 0;
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            if(d > thres) break;
            if(u != src) val++;
            for(auto [v, d1] : e[u]) {
                if(d + d1 >= dist[v]) continue;
                dist[v] = d + d1;
                pq.push({dist[v], v});
            }
        }
        return val;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = -1, minVal = INT_MAX;
        vector<vector<pair<int, int>>> e(n);
        for(auto &x : edges) {
            e[x[0]].push_back({x[1], x[2]});
            e[x[1]].push_back({x[0], x[2]});
        }
        for(int i = 0; i < n; i++) {
            int val = dijkstra(i, distanceThreshold, e);
            if(val <= minVal) minVal = val, ans = i;
        }
        return ans;
    }
};
