class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        vector<vector<int>> newMat(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int newJ;
                if(i % 2 == 0) newJ = (j + n - k) % n;
                else newJ = (j + k) % n;
                newMat[i][newJ] = mat[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] != newMat[i][j]) return false;
            }
        }
        return true;
    }
};
