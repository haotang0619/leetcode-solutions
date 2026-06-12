class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int s = m * n;
        vector<vector<int>> e(s, vector<int>({}));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int idx = i * n + j;
                if(grid[i][j] == '0') continue;
                if(i - 1 >= 0 && grid[i - 1][j] == '1') e[idx].push_back(idx - n);
                if(i + 1 < m && grid[i + 1][j] == '1') e[idx].push_back(idx + n);
                if(j - 1 >= 0 && grid[i][j - 1] == '1') e[idx].push_back(idx - 1);
                if(j + 1 < n && grid[i][j + 1] == '1') e[idx].push_back(idx + 1);
            }
        }
        int ans = 0;
        vector<bool> vis(s, false);
        stack<int> sk;
        for(int i = 0; i < s; i++) {
            if(vis[i]) continue;
            if(grid[i / n][i % n] == '0') continue;
            ans++;
            sk.push(i);
            vis[i] = true;
            while(!sk.empty()) {
                int top = sk.top();
                sk.pop();
                for(int x : e[top]) {
                    if(vis[x]) continue;
                    vis[x] = true;
                    sk.push(x);
                }
            }
        }
        return ans;
    }
};
