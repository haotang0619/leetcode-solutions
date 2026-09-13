class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> v(n * n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) v[grid[i][j]] = {i, j};
        }
        if(v[0].first != 0 || v[0].second != 0) return false;
        for(int idx = 0; idx < n * n - 1; idx++) {
            auto& [i1, j1] = v[idx];
            auto& [i2, j2] = v[idx + 1];
            int diff1 = abs(i1 - i2), diff2 = abs(j1 - j2);
            if(diff1 == 1 && diff2 == 2 || diff1 == 2 && diff2 == 1) continue;
            return false;
        }
        return true;
    }
};
