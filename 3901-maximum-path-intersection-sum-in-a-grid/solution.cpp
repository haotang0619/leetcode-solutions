class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MIN;
        // Find max subarray sum of each row with length >= 2
        for(int i = 0; i < m; i++) {
            vector<int> pSum(n, 0);
            for(int j = 0; j < n; j++) {
                pSum[j] = grid[i][j];
                if(j >= 1) pSum[j] += pSum[j - 1];
            }
            int minPrefix = 0;
            for(int j = 1; j < n; j++) {
                if(j >= 2) minPrefix = min(minPrefix, pSum[j - 2]);
                ans = max(ans, pSum[j] - minPrefix);
            }
        }
        // Find max subarray sum of each column with length >= 2
        for(int j = 0; j < n; j++) {
            vector<int> pSum(m, 0);
            for(int i = 0; i < m; i++) {
                pSum[i] = grid[i][j];
                if(i >= 1) pSum[i] += pSum[i - 1];
            }
            int minPrefix = 0;
            for(int i = 1; i < m; i++) {
                if(i >= 2) minPrefix = min(minPrefix, pSum[i - 2]);
                ans = max(ans, pSum[i] - minPrefix);
            }
        }
        // Special single share cell cases
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) ans = max(ans, grid[i][j]);
        }
        return ans;
    }
};
