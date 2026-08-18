class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> e(n);
        for(auto& x : edges) {
            e[x[0]].push_back({x[1], x[2]}), e[x[1]].push_back({x[0], x[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        // [d, u]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(dist[u] < d) continue;
            for(auto& [v, d1] : e[u]) {
                int d2 = d + d1;
                if(dist[v] <= d2) continue;
                if(disappear[v] <= d2) continue;
                dist[v] = d2;
                pq.push({d2, v});
            }
        }
        for(auto& x : dist) {
            if(x == INT_MAX) x = -1;
        }
        return dist;
    }
};
