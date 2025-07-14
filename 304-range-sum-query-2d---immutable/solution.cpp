class NumMatrix {
public:
    vector<vector<int>> pSum;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            pSum.push_back(vector<int>(n, 0));
            int rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += matrix[i][j];
                pSum[i][j] = rowSum;
                if(i > 0) pSum[i][j] += pSum[i - 1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pSum[row2][col2] - (row1 > 0 ? pSum[row1 - 1][col2] : 0) - (col1 > 0 ? pSum[row2][col1 - 1] : 0) + (row1 > 0 && col1 > 0 ? pSum[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
