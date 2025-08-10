class Solution {
public:
    void solve(int &ans, int &end, int &target, int cnt, int now, vector<bool> &seen, vector<vector<int>> &edges) {
        if(now == end) {
            if(target == cnt) ans++;
            return;
        }
        seen[now] = true;
        for(auto x : edges[now]) {
            if(seen[x]) continue;
            seen[x] = true;
            solve(ans, end, target, cnt + 1, x, seen, edges);
            seen[x] = false;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int size = m * n, cnt = 0;
        int start = -1, end = -1;
        vector<vector<int>> edges(size, vector<int>({}));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == -1) continue;
                cnt++;
                int idx = i * n + j;
                if(grid[i][j] == 1) start = idx;
                if(grid[i][j] == 2) end = idx;
                if(i > 0) {
                    int up = (i - 1) * n + j;
                    if(grid[i - 1][j] >= 0) edges[idx].push_back(up);
                }
                if(j > 0) {
                    int left = i * n + j - 1;
                    if(grid[i][j - 1] >= 0) edges[idx].push_back(left);
                }
                if(i < m - 1) {
                    int down = (i + 1) * n + j;
                    if(grid[i + 1][j] >= 0) edges[idx].push_back(down);
                }
                if(j < n - 1) {
                    int right = i * n + j + 1;
                    if(grid[i][j + 1] >= 0) edges[idx].push_back(right);
                }
            }
        }
        int ans = 0;
        vector<bool> seen(size, false);
        solve(ans, end, cnt, 1, start, seen, edges);
        return ans;
    }
};
