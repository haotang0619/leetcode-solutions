class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> e(n);
        for(int j = 0; j < n; j++) {
            for(int k = n - 1; k > j; k--) {
                bool valid = true;
                for(int i = 0; i < m; i++) {
                    if(abs(grid[i][k] - grid[i][j]) > limit) {
                        valid = false;
                        break;
                    };
                }
                if(valid) e[j].push_back(k);
            }
        }
        int ans = 1;
        for(int j = 0; j < n; j++) {
            stack<pair<int, int>> sk;
            sk.push({j, 1});
            vector<int> dist(n, 0);
            dist[j] = 1;
            while(!sk.empty()) {
                auto [u, len] = sk.top();
                sk.pop();
                if(dist[u] > len) continue;
                ans = max(ans, len);
                for(auto& v : e[u]) {
                    if(dist[v] >= len + 1) continue;
                    dist[v] = len + 1;
                    sk.push({v, dist[v]});
                }
            }
        }
        return ans;
    }
};
