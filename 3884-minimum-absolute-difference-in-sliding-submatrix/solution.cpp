class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int x = m - k + 1, y = n - k + 1;
        vector<vector<int>> ans(x, vector<int>(y, INT_MAX));
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                vector<int> v;
                for(int a = i; a < i + k; a++) {
                    for(int b = j; b < j + k; b++) {
                        v.push_back(grid[a][b]);
                    }
                }
                sort(v.begin(), v.end());
                for(int a = 1; a < k * k; a++) {
                    if(v[a] != v[a - 1]) ans[i][j] = min(ans[i][j], v[a] - v[a - 1]);
                }
                if(ans[i][j] == INT_MAX) ans[i][j] = 0;
            }
        }
        return ans;
    }
};
