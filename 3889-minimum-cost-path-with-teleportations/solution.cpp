class Solution {
public:
    int minCost(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dist(K + 1, vector<vector<int>>(m, vector<int>(n, INT_MAX)));
        dist[0][0][0] = 0;

        vector<vector<pair<int, int>>> indices(K);
        for(int k = 0; k < K; k++)  {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) indices[k].push_back({i, j});
            }
            sort(indices[k].begin(), indices[k].end(), [&](auto& a, auto& b) {
                auto& [a1, a2] = a;
                auto& [b1, b2] = b;
                return grid[a1][a2] > grid[b1][b2];
            });
        }
        
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq; // [d, k, i, j]
        pq.push({0, 0, 0, 0});
        
        int ans = INT_MAX;
        while(!pq.empty()) {
            auto [d, k, ui, uj] = pq.top();
            pq.pop();
            if(d > dist[k][ui][uj]) continue;
            if(ui == m - 1 && uj == n - 1) {
                ans = min(ans, dist[k][ui][uj]);
                break;
            }
            if(ui + 1 < m && dist[k][ui + 1][uj] > d + grid[ui + 1][uj]) {
                dist[k][ui + 1][uj] = d + grid[ui + 1][uj];
                pq.push({dist[k][ui + 1][uj], k, ui + 1, uj});
            }
            if(uj + 1 < n && dist[k][ui][uj + 1] > d + grid[ui][uj + 1]) {
                dist[k][ui][uj + 1] = d + grid[ui][uj + 1];
                pq.push({dist[k][ui][uj + 1], k, ui, uj + 1});
            }
            if(k == K) continue;
            while(!indices[k].empty()) {
                auto [vi, vj] = indices[k].back();
                if(grid[vi][vj] > grid[ui][uj]) break;
                if(dist[k][vi][vj] > d) {
                    dist[k + 1][vi][vj] = d;
                    pq.push({d, k + 1, vi, vj});
                };
                indices[k].pop_back();
            }
        }
        return ans;
    }
};
