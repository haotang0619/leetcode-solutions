class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        for(auto x : grid) for(auto y : x) sum += y;
        int m = grid.size(), n = grid[0].size();
        long long now_sum = 0;
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) now_sum += grid[i][j];
            if(now_sum * 2 == sum) return true;
        }
        now_sum = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) now_sum += grid[j][i];
            if(now_sum * 2 == sum) return true;
        }
        return false;
    }
};
