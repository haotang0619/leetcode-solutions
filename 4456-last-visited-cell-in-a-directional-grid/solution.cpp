class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int x = 0, y = 0;
        while(true) {
            int x1 = x, y1 = y;
            vis[x][y] = true;
            char d = grid[x][y];
            if(d == 'L') y1--;
            else if(d == 'R') y1++;
            else if(d == 'U') x1--;
            else x1++;
            if(x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) return {x, y};
            if(vis[x1][y1]) return {x, y};
            x = x1, y = y1;
        }
    }
};
