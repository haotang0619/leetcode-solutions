class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> e(n);
        for(auto &x : edges) e[x[0]].push_back({x[1], x[2]});
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // [dist, idx, by_far]
        pq.push({0, 0, 1});
        while(!pq.empty()) {
            auto [d, u, cons] = pq.top();
            pq.pop();
            if(dist[u][cons] > d) continue;
            for(auto [v, d1] : e[u]) {
                int nextCons = 1;
                if(labels[u] == labels[v]) nextCons = cons + 1;
                if(nextCons <= k && dist[v][nextCons] > d + d1) {
                    dist[v][nextCons] = d + d1;
                    pq.push({dist[v][nextCons], v, nextCons});
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++) ans = min(ans, dist[n - 1][i]);
        return ans == INT_MAX ? -1 : ans;
    }
};
