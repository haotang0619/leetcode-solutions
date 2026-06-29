class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j) {
        vector<bool> vis(9, false);
        for(int x = i; x < i + 3; x++) {
            int sum = 0;
            for(int y = j; y < j + 3; y++) {
                if(grid[x][y] < 1 || grid[x][y] > 9) return false;
                if(vis[grid[x][y] - 1]) return false;
                vis[grid[x][y] - 1] = true;
                sum += grid[x][y];
            }
            if(sum != 15) return false;
        }
        for(int y = j; y < j + 3; y++) {
            int sum = 0;
            for(int x = i; x < i + 3; x++) sum += grid[x][y];
            if(sum != 15) return false;
        }
        if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15) return false;
        if(grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != 15) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                if(check(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};
