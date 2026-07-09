class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<int> dist(m * n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // [d, u]
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            int ux = u / n, uy = u % n;
            for(auto& [x, y] : dir) {
                int vx = ux + x, vy = uy + y;
                if(vx < 0 || vx >= m || vy < 0 || vy >= n) continue;
                int v = vx * n + vy;
                int gap = abs(heights[ux][uy] - heights[vx][vy]);
                int d1 = max(d, gap);
                if(dist[v] <= d1) continue;
                dist[v] = d1;
                pq.push({d1, v});
            }
        }
        return dist[m * n - 1];
    }
};
