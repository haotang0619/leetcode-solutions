class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int traverse(vector<vector<int>>& grid, int u, vector<bool>& vis) {
        int m = grid.size(), n = grid[0].size();
        int ui = u / n, uj = u % n;
        int now = grid[ui][uj], maxChild = 0;
        for(auto& [x, y] : dir) {
            int vi = ui + x, vj = uj + y, v = vi * n + vj;
            if(vi < 0 || vi >= m || vj < 0 || vj >= n) continue;
            if(grid[vi][vj] == 0) continue;
            if(vis[v]) continue;
            vis[v] = true;
            maxChild = max(maxChild, traverse(grid, v, vis));
            vis[v] = false;
        }
        return now + maxChild;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                vector<bool> vis(m * n, false);
                int u = i * n + j;
                vis[u] = true;
                ans = max(ans, traverse(grid, u, vis));
            }
        }
        return ans;
    }
};
