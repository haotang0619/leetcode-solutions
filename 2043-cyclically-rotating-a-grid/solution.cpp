class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int l = 0; l < layers; l++) {
            int x = l, y = l;
            vector<vector<int>> orders;
            while(x < m - l) {
                orders.push_back({x, y});
                x++;
            }
            x--, y++;
            while(y < n - l) {
                orders.push_back({x, y});
                y++;
            }
            y--, x--;
            while(x >= l) {
                orders.push_back({x, y});
                x--;
            }
            x++, y--;
            while(y > l) {
                orders.push_back({x, y});
                y--;
            }
            int shift = k % orders.size();
            for(int i = 0; i < orders.size(); i++) {
                int j = (i + shift) % orders.size();
                ans[orders[j][0]][orders[j][1]] = grid[orders[i][0]][orders[i][1]];
            }
        }
        return ans;
    }
};
