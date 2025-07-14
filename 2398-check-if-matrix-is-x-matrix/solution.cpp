class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bool isDiag = (i == j) || (i + j == n - 1);
                if(isDiag && grid[i][j] == 0 || !isDiag && grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};
