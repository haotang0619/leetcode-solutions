class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> edges(m * n, vector<int>({}));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int idx = i * n + j, i1 = idx + 1, i2 = idx + n;
                if(j < n - 1 && grid[i][j] > 0 && grid[i][j + 1] > 0) {
                    edges[idx].push_back(i1);
                    edges[i1].push_back(idx);
                }
                if(i < m - 1 && grid[i][j] > 0 && grid[i + 1][j] > 0) {
                    edges[idx].push_back(i2);
                    edges[i2].push_back(idx);
                }
            }
        }
        vector<bool> seen(m * n, false);
        int ans = 0;
        for(int i = 0; i < m * n; i++) {
            if(seen[i]) continue;
            if(grid[i / n][i % n] == 0) {
                seen[i] = true;
                continue;
            }
            stack<int> sk;
            sk.push(i);
            long long now = 0;
            while(!sk.empty()) {
                int top = sk.top();
                seen[top] = true;
                now += (long long)grid[top / n][top % n];
                sk.pop();
                for(auto x : edges[top]) {
                    if(!seen[x]) {
                        seen[x] = true;
                        sk.push(x);
                    }
                }
            }
            if(now % k == 0) ans++;
        }
        return ans;
    }
};
