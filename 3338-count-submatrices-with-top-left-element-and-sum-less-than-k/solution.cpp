class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            int rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += grid[i][j];
                sum[i][j] = rowSum;
                if(i > 0) sum[i][j] += sum[i - 1][j];
                ans += sum[i][j] <= k ? 1 : 0;
            }
        }
        return ans;
    }
};
