class Solution {
public:
    void checkMinTwo(vector<pair<int, int>>& minTwo, int num, int idx) {
        auto& [mn1, idx1] = minTwo[0];
        auto& [mn2, idx2] = minTwo[1];
        if(num < mn2) mn2 = num, idx2 = idx;
        if(mn2 < mn1) swap(minTwo[0], minTwo[1]);
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<pair<int, int>> minTwo(2, {INT_MAX, -1}); // [num, idx]
        int n = grid.size();
        for(int i = 0; i < n; i++) checkMinTwo(minTwo, grid[0][i], i);
        if(n == 1) return minTwo[0].first;

        for(int i = 1; i < n; i++) {
            vector<pair<int, int>> newMinTwo(2, {INT_MAX, -1});
            for(int j = 0; j < n; j++) {
                int val = minTwo[0].first + grid[i][j];
                if(minTwo[0].second == j) val = minTwo[1].first + grid[i][j];
                checkMinTwo(newMinTwo, val, j);
            }
            minTwo = newMinTwo;
        }
        return minTwo[0].first;
    }
};
