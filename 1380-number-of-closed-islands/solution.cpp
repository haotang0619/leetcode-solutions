class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 || vis[i][j]) continue;
                bool flag = true;
                queue<pair<int, int>> qu;
                qu.push({i, j});
                vis[i][j] = true;
                while(!qu.empty()) {
                    auto [i1, j1] = qu.front();
                    qu.pop();
                    for(auto& [x, y] : dir) {
                        int i2 = i1 + x, j2 = j1 + y;
                        if(i2 < 0 || i2 >= m || j2 < 0 || j2 >= n) {
                            flag = false;
                            continue;
                        }
                        if(grid[i2][j2] == 1 || vis[i2][j2]) continue;
                        qu.push({i2, j2});
                        vis[i2][j2] = true;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};
