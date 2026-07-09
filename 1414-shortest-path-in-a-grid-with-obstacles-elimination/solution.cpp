class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int shortestPath(vector<vector<int>>& grid, int K) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m * n, vector<int>(K + 1, INT_MAX));
        dist[0][0] = 0;
        queue<tuple<int, int, int>> qu; // [d, k, u]
        qu.push({0, 0, 0});
        int ans = -1;
        while(!qu.empty()) {
            auto [d, k, u] = qu.front();
            qu.pop();
            if(d > dist[u][k]) continue;
            if(u == m * n - 1) {
                if(ans == -1) ans = d;
                else ans = min(ans, d);
                continue;
            }
            int i = u / n, j = u % n;
            for(auto& [x, y] : dir) {
                int i1 = i + x, j1 = j + y;
                if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) continue;
                bool isObs = grid[i1][j1] == 1;
                if(isObs && (k == K)) continue;
                int v = i1 * n + j1;
                if(d + 1 >= dist[v][k + isObs]) continue;
                dist[v][k + isObs] = d + 1;
                qu.push({dist[v][k + isObs], k + isObs, v});
            }
        }
        return ans;
    }
};
