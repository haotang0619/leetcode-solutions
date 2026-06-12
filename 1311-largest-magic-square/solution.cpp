class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rowSum(m, vector<int>(n, 0)), colSum(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowSum[i][j] = colSum[i][j] = grid[i][j];
                if(i > 0) colSum[i][j] += colSum[i - 1][j];
                if(j > 0) rowSum[i][j] += rowSum[i][j - 1];
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int maxK = min(m - i, n - j);
                for(int k = ans + 1; k <= maxK; k++) {
                    bool valid = true;
                    // rowSum
                    int base = rowSum[i][j + k - 1] - (j > 0 ? rowSum[i][j - 1] : 0);
                    for(int x = i + 1; x < i + k && valid; x++) {
                        int now = rowSum[x][j + k - 1] - (j > 0 ? rowSum[x][j - 1] : 0);
                        if(now != base) valid = false;
                    }
                    // colSum
                    for(int y = j; y < j + k && valid; y++) {
                        int now = colSum[i + k - 1][y] - (i > 0 ? colSum[i - 1][y] : 0);
                        if(now != base) valid = false;
                    }
                    // diagonal
                    int diaSum1 = 0, diaSum2 = 0;
                    for(int x = i, y = j; x < i + k && valid; x++, y++) {
                        diaSum1 += grid[x][y];
                    }
                    if(diaSum1 != base) valid = false;
                    for(int x = i, y = j + k - 1; x < i + k && valid; x++, y--) {
                        diaSum2 += grid[x][y];
                    }
                    if(diaSum2 != base) valid = false;
                    if(valid) ans = k;
                }
            }
        }
        return ans;
    }
};
