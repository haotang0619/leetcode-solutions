class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dist[k + 1][4][m][n]; // [t][dir][x][y]
        int tot = (k + 1) * 4 * m * n;
        fill_n(&dist[0][0][0][0], tot, INT_MAX);
        for(int dir = 0; dir < 4; dir++) dist[0][dir][0][0] = grid[0][0];
        priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<>> pq; // [d, t, dir, x, y]
        pq.push({grid[0][0], 0, -1, 0, 0});
        
        while(!pq.empty()) {
            auto [d, t, dir, x, y] = pq.top();
            pq.pop();
            
            if(dir != -1 && dist[t][dir][x][y] < d) continue;
            if(x == m - 1 && y == n - 1) return d;
            
            int dir1 = -1;
            for(auto& [dx, dy] : dirs) {
                dir1++;
                int x1 = x + dx, y1 = y + dy;
                if(x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
                
                int t1 = t;
                if(dir != -1 && dir != dir1) t1++;
                if(t1 > k) continue;
                
                int d1 = d + grid[x1][y1];
                if(dist[t1][dir1][x1][y1] <= d1) continue;
                
                dist[t1][dir1][x1][y1] = d1;
                pq.push({d1, t1, dir1, x1, y1});
            }
        }
        return -1;
    }
};
