class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pSum(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            int prev = 0;
            for(int j = 0; j < n; j++) {
                pSum[i][j] = prev + (matrix[i][j] - '0');
                if(i > 0) pSum[i][j] += pSum[i - 1][j];
                prev += (matrix[i][j] - '0');
            }
        }
        for(int i = min(m, n); i >= 1; i--) {
            for(int x = 0; x < m - i + 1; x++) {
                for(int y = 0; y < n - i + 1; y++) {
                    int sum = 0;
                    sum += pSum[x + i - 1][y + i - 1];
                    if(x > 0) sum -= pSum[x - 1][y + i - 1];
                    if(y > 0) sum -= pSum[x + i - 1][y - 1];
                    if(x > 0 && y > 0) sum += pSum[x - 1][y - 1];
                    if(sum == i * i) return sum;
                }
            }
        }
        return 0;
    }
};
