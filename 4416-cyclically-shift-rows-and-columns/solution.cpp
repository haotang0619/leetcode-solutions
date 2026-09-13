class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> grid1(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int k = rowShift[i];
                grid1[i][(j - k + n) % n] = grid[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                int k = colShift[j];
                ans[(i - k + n) % n][j] = grid1[i][j];
            }
        }
        return ans;
    }
};
