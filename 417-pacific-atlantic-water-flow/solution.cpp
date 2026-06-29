class Solution {
public:
    int getHeight(vector<vector<int>>& heights, int x, int y) {
        int m = heights.size(), n = heights[0].size();
        if(x == 0 || y == 0 || x == m + 1 || y == n + 1) return 0;
        return heights[x - 1][y - 1];
    }

    vector<pair<int, int>> getEdge(vector<vector<int>>& heights, int x, int y) {
        int curr = getHeight(heights, x, y);
        int m = heights.size(), n = heights[0].size();
        vector<pair<int, int>> e;
        if(x - 1 >= 0 && getHeight(heights, x - 1, y) >= curr) e.push_back({x - 1, y});
        if(x + 1 <= m + 1 && getHeight(heights, x + 1, y) >= curr) e.push_back({x + 1, y});
        if(y - 1 >= 0 && getHeight(heights, x, y - 1) >= curr) e.push_back({x, y - 1});
        if(y + 1 <= n + 1 && getHeight(heights, x, y + 1) >= curr) e.push_back({x, y + 1});
        return e;
    }

    void bfs(set<pair<int, int>>& vis, vector<vector<int>>& heights, int x, int y) {
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> qu;
        qu.push({x, y});
        while(!qu.empty()) {
            auto [x1, y1] = qu.front();
            qu.pop();
            for(auto [x2, y2] : getEdge(heights, x1, y1)) {
                if(vis.contains({x2, y2})) continue;
                if(x2 == 0 || y2 == 0 || x2 == m + 1 || y2 == n + 1) continue;
                vis.insert({x2, y2});
                qu.push({x2, y2});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        set<pair<int, int>> vis1, vis2;
        // Pacific
        for(int j = 0; j <= n + 1; j++) bfs(vis1, heights, 0, j);
        for(int i = 1; i <= m; i++) bfs(vis1, heights, i, 0);
        // Atlantic
        for(int j = 0; j <= n + 1; j++) bfs(vis2, heights, m + 1, j);
        for(int i = 1; i <= m; i++) bfs(vis2, heights, i, n + 1);
        vector<vector<int>> ans;
        for(auto [x, y] : vis1) {
            if(x == 0 || y == 0 || x == m + 1 || y == n + 1) continue;
            if(vis2.contains({x, y})) ans.push_back({x - 1, y - 1});
        }
        return ans;
    }
};
