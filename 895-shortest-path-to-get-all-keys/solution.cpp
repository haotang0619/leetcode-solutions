class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int keys = 0, x = 0, y = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char& cell = grid[i][j];
                if(cell >= 'a' && cell <= 'z') keys++;
                if(cell == '@') x = i, y = j;
            }
        }
        int stats = (1 << keys);
        vector<vector<int>> dist(m * n, vector<int>(stats, INT_MAX));
        dist[x * n + y][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // [d, stat, u]
        pq.push({0, 0, x * n + y});
        while(!pq.empty()) {
            auto [d, st, u] = pq.top();
            pq.pop();
            if(d > dist[u][st]) continue;
            if(st == stats - 1) return d;
            int ux = u / n, uy = u % n;
            for(auto& [dx, dy] : dir) {
                int vx = ux + dx, vy = uy + dy;
                if(vx < 0 || vx >= m || vy < 0 || vy >= n) continue;
                if(grid[vx][vy] == '#') continue;
                
                bool isLock = grid[vx][vy] >= 'A' && grid[vx][vy] <= 'Z';
                int v = vx * n + vy;
                if(grid[vx][vy] == '.' || grid[vx][vy] == '@' || isLock) {
                    if(isLock) {
                        int lockId = grid[vx][vy] - 'A';
                        bool hasKey = ((1 << lockId) & st) > 0;
                        if(!hasKey) continue;
                    }
                    if(dist[v][st] <= d + 1) continue;
                    dist[v][st] = d + 1;
                    pq.push({dist[v][st], st, v});
                } else {
                    int keyId = grid[vx][vy] - 'a';
                    int newSt = st | (1 << keyId);
                    if(dist[v][newSt] <= d + 1) continue;
                    dist[v][newSt] = d + 1;
                    pq.push({dist[v][newSt], newSt, v});
                }
            }
        }
        return -1;
    }
};
