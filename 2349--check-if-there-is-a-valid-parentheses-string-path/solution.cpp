class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')') return false;
        int m = grid.size(), n = grid[0].size(), steps = m + n - 1;
        if(steps & 1) return false;
        
        int mx = steps / 2;
        bool vis[m][n][mx + 1];
        memset(vis, 0, sizeof(vis));
        vis[0][0][1] = true;
        queue<tuple<int, int, int>> qu; // [i][j][count]
        qu.push({0, 0, 1});

        while(!qu.empty()) {
            auto [i, j, cnt] = qu.front();
            qu.pop();
            if(i == m - 1 && j == n - 1 && cnt == 0) return true;
            
            for(auto& [x, y] : dirs) {
                int i1 = i + x, j1 = j + y, cnt1 = cnt;
                if(i1 >= m || j1 >= n) continue;
                if(grid[i1][j1] == '(') cnt1++;
                else cnt1--;
                if(cnt1 < 0 || cnt1 > mx) continue;
                if(vis[i1][j1][cnt1]) continue;
                vis[i1][j1][cnt1] = true;
                qu.push({i1, j1, cnt1});
            }
        }
        return false;
    }
};
