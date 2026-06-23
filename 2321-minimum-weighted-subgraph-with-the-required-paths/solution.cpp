// Saw a solution
class Solution {
public:
    vector<long long> dijkstra(vector<vector<pair<int, int>>>& e, int src) {
        int n = e.size();
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, d1] : e[u]) {
                if(d + d1 < dist[v]) {
                    dist[v] = d + d1;
                    pq.push({d + d1, v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> e1(n), e2(n);
        for(auto &x : edges) {
            e1[x[0]].push_back({x[1], x[2]});
            e2[x[1]].push_back({x[0], x[2]});
        }
        vector<long long> dist1 = dijkstra(e1, src1), dist2 = dijkstra(e1, src2), dist3 = dijkstra(e2, dest);
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            if(dist1[i] != LLONG_MAX && dist2[i] != LLONG_MAX && dist3[i] != LLONG_MAX) {
                ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
            }
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
};
