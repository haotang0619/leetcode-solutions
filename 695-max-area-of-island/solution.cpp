class Solution {
public:
    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& vis, int i, int j) {
        int m = grid.size(), n = grid[0].size(), now = 0;
        queue<pair<int, int>> qu;
        qu.push({i, j});
        vis.insert({i, j});
        while(!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            now++;
            if(!vis.contains({x - 1, y}) && x - 1 >= 0 && grid[x - 1][y] == 1) {
                vis.insert({x - 1, y});
                qu.push({x - 1, y});
            }
            if(!vis.contains({x + 1, y}) && x + 1 < m && grid[x + 1][y] == 1) {
                vis.insert({x + 1, y});
                qu.push({x + 1, y});
            }
            if(!vis.contains({x, y - 1}) && y - 1 >= 0 && grid[x][y - 1] == 1) {
                vis.insert({x, y - 1});
                qu.push({x, y - 1});
            }
            if(!vis.contains({x, y + 1}) && y + 1 < n && grid[x][y + 1] == 1) {
                vis.insert({x, y + 1});
                qu.push({x, y + 1});
            }
        }
        return now;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        set<pair<int, int>> vis;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                if(vis.contains({i, j})) continue;
                ans = max(ans, bfs(grid, vis, i, j));
            }
        }
        return ans;
    }
};
