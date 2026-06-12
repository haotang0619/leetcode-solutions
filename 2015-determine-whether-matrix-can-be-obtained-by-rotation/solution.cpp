class Solution {
public:
    void rotate(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int newI = j, newJ = n - 1 - i;
                mat2[newI][newJ] = mat1[i][j];
            }
        }
    }

    bool compare(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat1[i][j] != mat2[i][j]) return false;
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> mat2(n, vector<int>(n, 0));
        for(int i = 0; i < 4; i++) {
            if(i % 2 == 0) {
                rotate(mat, mat2);
                if(compare(mat2, target)) return true;
            }
            else {
                rotate(mat2, mat);
                if(compare(mat, target)) return true;
            }
        }
        return false;
    }
};
