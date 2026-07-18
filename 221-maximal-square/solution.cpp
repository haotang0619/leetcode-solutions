class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pSum(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            int rowSum = 0;
            for(int j = 0; j < n; j++) {
                pSum[i][j] = (matrix[i][j] - '0') + rowSum;
                if(i > 0) pSum[i][j] += pSum[i - 1][j];
                rowSum += (matrix[i][j] - '0');
            }
        }
        for(int len = min(m, n); len >= 1; len--) {
            for(int i = 0; i + len <= m; i++) {
                for(int j = 0; j + len <= n; j++) {
                    int sum = pSum[i + len - 1][j + len - 1];
                    if(i > 0) sum -= pSum[i - 1][j + len - 1];
                    if(j > 0) sum -= pSum[i + len - 1][j - 1];
                    if(i > 0 && j > 0) sum += pSum[i - 1][j - 1];
                    if(sum == len * len) return sum;
                }
            }
        }
        return 0;
    }
};
