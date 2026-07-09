class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> fac(n, vector<int>(n, INT_MAX));
        queue<tuple<int, int, int>> qu; // [i, j, d]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    fac[i][j] = 0;
                    qu.push({i, j, 0});
                }
            }
        }
        while(!qu.empty()) {
            auto [i, j, d] = qu.front();
            qu.pop();
            for(auto& [x, y] : dir) {
                if(i + x >= 0 && i + x < n && j + y >= 0 && j + y < n && fac[i + x][j + y] > d + 1) {
                    qu.push({i + x, j + y, d + 1});
                    fac[i + x][j + y] = d + 1;
                }
            }
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int maxD = (n - 1) * 2;
        dist[0][0] = maxD - fac[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // [d, i, j]
        pq.push({dist[0][0], 0, 0});
        while(!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if(d > dist[i][j]) continue;
            for(auto& [x, y] : dir) {
                if(i + x >= 0 && i + x < n && j + y >= 0 && j + y < n) {
                    int newD = max(dist[i][j], maxD - fac[i + x][j + y]);
                    if(dist[i + x][j + y] <= newD) continue;
                    dist[i + x][j + y] = newD;
                    pq.push({newD, i + x, j + y});
                }
            }
        }
        return maxD - dist[n - 1][n - 1];
    }
};
