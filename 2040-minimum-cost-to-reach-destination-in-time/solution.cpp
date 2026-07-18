class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> e(n);
        for(auto& x : edges) {
            e[x[0]].push_back({x[1], x[2]});
            e[x[1]].push_back({x[0], x[2]});
        }
        vector<vector<int>> dist(maxTime + 1, vector<int>(n, INT_MAX));
        dist[0][0] = passingFees[0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // [d, t, u]
        pq.push({dist[0][0], 0, 0});
        while(!pq.empty()) {
            auto [d, t, u] = pq.top();
            pq.pop();
            if(d > dist[t][u]) continue;
            if(u == n - 1) return d;
            for(auto& [v, t1] : e[u]) {
                if(t + t1 > maxTime) continue;
                if(d + passingFees[v] >= dist[t + t1][v]) continue;
                dist[t + t1][v] = d + passingFees[v];
                pq.push({dist[t + t1][v], t + t1, v});
            }
        }
        return -1;
    }
};
