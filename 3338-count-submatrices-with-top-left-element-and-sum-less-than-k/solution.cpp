class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<long long>> pSum(m, vector<long long>(n, 0));
        for(int i = 0; i < m; i++) {
            long long rowSum = 0;
            for(int j = 0; j < n; j++) {
                pSum[i][j] = rowSum + grid[i][j];
                if(i > 0) pSum[i][j] += pSum[i - 1][j];
                if(pSum[i][j] <= k) ans++;
                rowSum += grid[i][j];
            }
        }
        return ans;
    }
};
