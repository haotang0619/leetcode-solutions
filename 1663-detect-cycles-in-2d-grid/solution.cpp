class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), l = m * n;
        vector<vector<int>> e(l, vector<int>({}));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int idx = i * n + j, val = grid[i][j];
                if(i > 0 && grid[i - 1][j] == val) {
                    e[idx].push_back((i - 1) * n + j);
                }
                if(j > 0 && grid[i][j - 1] == val) {
                    e[idx].push_back(i * n + j - 1);
                }
                if(i < m - 1 && grid[i + 1][j] == val) {
                    e[idx].push_back((i + 1) * n + j);
                }
                if(j < n - 1 && grid[i][j + 1] == val) {
                    e[idx].push_back(i * n + j + 1);
                }
            }
        }
        vector<bool> visit(l, false);
        stack<pair<int, int>> sk;
        for(int i = 0; i < l; i++) {
            if(visit[i]) continue;
            sk.push({i, -1});
            visit[i] = true;
            while(!sk.empty()) {
                auto top = sk.top();
                int node = top.first, parent = top.second;
                sk.pop();
                for(auto x : e[node]) {
                    if(x == parent) continue;
                    if(visit[x]) return true;
                    visit[x] = true;
                    sk.push({x, node});
                }
            }
        }
        return false;
    }
};
