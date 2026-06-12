class Solution {
public:
    void maintainTop3(vector<int>& ans, int now) {
        if(ans[0] == now || ans[1] == now || ans[2] == now) return;
        if(now > ans[2]) ans[2] = now;
        if(ans[2] > ans[1]) swap(ans[1], ans[2]);
        if(ans[1] > ans[0]) swap(ans[0], ans[1]);
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int l = (min(m, n) - 1) / 2;
        vector<int> ans(3, -1);
        for(int i = 0; i <= l; i++) {
            for(int x = 0; x < m; x++) {
                for(int y = 0; y < n; y++) {
                    if(i == 0) {
                        maintainTop3(ans, grid[x][y]);
                        continue;
                    }
                    int a = x, b = y, sum = 0;
                    for(int dir = 0; dir < 4; dir++) {
                        for(int j = 0; j < i; j++) {
                            if(dir == 0) a++, b--;
                            else if(dir == 1) a++, b++;
                            else if(dir == 2) a--, b++;
                            else a--, b--;
                            if(a < 0 || a >= m || b < 0 || b >= n) {
                                sum = -1;
                                break;
                            }
                            sum += grid[a][b];
                        }
                        if(sum == -1) break;
                    }
                    if(sum >= 0) maintainTop3(ans, sum);
                }
            }
        }
        for(int i = 2; i >= 0; i--) {
            if(ans[i] == -1) ans.pop_back();
        }
        return ans;
    }
};
