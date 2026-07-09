class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        dist[0][0] = health - grid[0][0];
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        while(!pq.empty()) {
            auto [h, coord] = pq.top();
            auto [i, j] = coord;
            pq.pop();
            if(dist[i][j] < h) continue;
            for(auto& [x, y] : dir) {
                int i1 = i + x, j1 = j + y;
                if(i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) continue;
                if(h - grid[i1][j1] <= dist[i1][j1]) continue;
                dist[i1][j1] = h - grid[i1][j1];
                pq.push({dist[i1][j1], {i1, j1}});
            }
        }
        return dist[m - 1][n - 1] > 0;
    }
};
