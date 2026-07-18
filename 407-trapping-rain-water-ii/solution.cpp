// This version is from a solution
class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0, m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        // [h, i, j]
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        for(int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            vis[i][0] = vis[i][n - 1] = true;
        }
        for(int i = 1; i < n - 1; i++) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[m - 1][i], m - 1, i});
            vis[0][i] = vis[m - 1][i] = true;
        }
        while(!pq.empty()) {
            auto [h, i, j] = pq.top();
            pq.pop();
            for(auto& [x, y] : dir) {
                int i1 = i + x, j1 = j + y;
                if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) continue;
                if(vis[i1][j1]) continue;
                vis[i1][j1] = true;
                int h1 = h1 = heightMap[i1][j1];
                if(h1 < h) ans += h - h1;
                pq.push({max(h, h1), i1, j1});
            }
        }
        return ans;
    }
};
