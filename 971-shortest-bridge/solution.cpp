class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<tuple<int, int, int>> qut; // [i, j, step]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                vis[i][j] = true;
                queue<pair<int, int>> qu; // [i, j]
                qu.push({i, j});
                qut.push({i, j, 0});
                while(!qu.empty()) {
                    auto [i1, j1] = qu.front();
                    qu.pop();
                    for(auto& [x, y] : dir) {
                        int i2 = i1 + x, j2 = j1 + y;
                        if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= n) continue;
                        if(grid[i2][j2] == 0 || vis[i2][j2]) continue;
                        vis[i2][j2] = true;
                        qu.push({i2, j2});
                        qut.push({i2, j2, 0});
                    }
                }
                break;
            }
            if(qut.size() > 0) break;
        }
        while(!qut.empty()) {
            auto [i1, j1, step] = qut.front();
            qut.pop();
            for(auto& [x, y] : dir) {
                int i2 = i1 + x, j2 = j1 + y;
                if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= n) continue;
                if(vis[i2][j2]) continue;
                if(grid[i2][j2] == 1) return step;
                vis[i2][j2] = true;
                qut.push({i2, j2, step + 1});
            }
        }
        return -1;
    }
};
