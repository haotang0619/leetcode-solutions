class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            int rowSum = 0;
            for(int j = 0; j < n; j++) {
                sum[i][j] = mat[i][j];
                if(i > 0) sum[i][j] += sum[i - 1][j];
                if(j > 0) sum[i][j] += rowSum;
                rowSum += mat[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int minK = ans + 1, maxK = min(m - i, n - j);
                for(int k = minK; k <= maxK; k++) {
                    int nowSum = sum[i + k - 1][j + k - 1];
                    if(i > 0) nowSum -= sum[i - 1][j + k - 1];
                    if(j > 0) nowSum -= sum[i + k - 1][j - 1];
                    if(i > 0 && j > 0) nowSum += sum[i - 1][j - 1];
                    if(nowSum <= threshold) ans = k;
                }
            }
        }
        return ans;
    }
};
