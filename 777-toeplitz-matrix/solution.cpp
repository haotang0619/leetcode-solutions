class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = m - 1; i >= 0; i--) {
            int now = matrix[i][0];
            for(int x = i + 1, y = 1; x < m && y < n; x++, y++) {
                if(matrix[x][y] != now) return false;
            }
        }
        for(int j = 1; j < n; j++) {
            int now = matrix[0][j];
            for(int x = 1, y = j + 1; x < m && y < n; x++, y++) {
                if(matrix[x][y] != now) return false;
            }
        }
        return true;
    }
};
