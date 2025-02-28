class Solution {
public:
    int random = 1e9 + 7;

    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            bool flag = false;
            for(int j = 0; j < n; j++) {
                flag = flag || matrix[i][j] == 0;
            }
            for(int j = 0; j < n; j++) {
                if(flag) matrix[i][j] = matrix[i][j] == 0 ? 0 : random;
            }
        }
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < m; j++) {
                flag = flag || matrix[j][i] == 0;
            }
            for(int j = 0; j < m; j++) {
                if(flag) matrix[j][i] = matrix[j][i] == 0 ? 0 : random;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] == random ? 0 : matrix[i][j];
            }
        }
    }
};
