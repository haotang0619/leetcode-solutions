class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= x && i < x + k && j >= y && j < y + k) {
                    ans[i][j] = grid[x + k - 1 - (i - x)][j];
                } else ans[i][j] = grid[i][j];
            }
        }
        return ans;
    }
};
