class Solution {
public:
    // Saw all hints
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> prefixProducts(m, vector<long long>(n + 1, 1));
        vector<vector<long long>> suffixProducts(m, vector<long long>(n + 1, 1));
        for(int i = 0; i < m; i++) {
            prefixProducts[i][0] = grid[i][0];
            for(int j = 1; j < n; j++) {
                prefixProducts[i][j] = prefixProducts[i][j - 1] * grid[i][j] % mod;
            }
            prefixProducts[i][n] = prefixProducts[i][n - 1];
            if(i > 0) prefixProducts[i][n] = prefixProducts[i][n] * prefixProducts[i - 1][n] % mod;
        }
        for(int i = m - 1; i >= 0; i--) {
            suffixProducts[i][n - 1] = grid[i][n - 1];
            for(int j = n - 2; j >= 0; j--) {
                suffixProducts[i][j] = suffixProducts[i][j + 1] * grid[i][j] % mod;
            }
            suffixProducts[i][n] = suffixProducts[i][0];
            if(i < m - 1) suffixProducts[i][n] = suffixProducts[i][n] * suffixProducts[i + 1][n] % mod;
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                long long now = 1;
                if(i > 0) now = now * prefixProducts[i - 1][n] % mod;
                if(i < m - 1) now = now * suffixProducts[i + 1][n] % mod;
                if(j > 0) now = now * prefixProducts[i][j - 1] % mod;
                if(j < n - 1) now = now * suffixProducts[i][j + 1] % mod;
                ans[i][j] = now;
            }
        }
        return ans;
    }
};
