class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        queue<pair<int, int>> qu; // [u, d]
        vector<bool> vis(n * n, false);
        qu.push({0, 1});
        vis[0] = true;
        while(!qu.empty()) {
            auto [u, d] = qu.front();
            qu.pop();
            if(u == n * n - 1) return d;
            int ux = u / n, uy = u % n;
            for(auto& [x, y] : dir) {
                int vx = ux + x, vy = uy + y, v = vx * n + vy;
                if(vx < 0 || vx >= n || vy < 0 || vy >= n) continue;
                if(grid[vx][vy] == 1) continue;
                if(vis[v]) continue;
                qu.push({v, d + 1});
                vis[v] = true;
            }
        }
        return -1;
    }
};
