class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist;
        dist.resize(n, vector<int>(n, 1e9));
        dist[0][0] = grid[0][0];
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        pq.push({dist[0][0], {0, 0}});
        set<vector<int>> st;
        while(st.size() < n * n) {
            pair<int, vector<int>> p = pq.top();
            pq.pop();
            int d = p.first, i = p.second[0], j = p.second[1];
            if(st.find({i, j}) != st.end()) continue;
            if(i - 1 >= 0 && st.find({i - 1, j}) == st.end()) {
                int newDist = min(max(d, grid[i - 1][j]), dist[i - 1][j]);
                if(newDist < dist[i - 1][j]) {
                    dist[i - 1][j] = newDist;
                    pq.push({newDist, {i - 1, j}});
                }
            }
            if(j - 1 >= 0 && st.find({i, j - 1}) == st.end()) {
                int newDist = min(max(d, grid[i][j - 1]), dist[i][j - 1]);
                if(newDist < dist[i][j - 1]) {
                    dist[i][j - 1] = newDist;
                    pq.push({newDist, {i, j - 1}});
                }
            }
            if(i + 1 < n && st.find({i + 1, j}) == st.end()) {
                int newDist = min(max(d, grid[i + 1][j]), dist[i + 1][j]);
                if(newDist < dist[i + 1][j]) {
                    dist[i + 1][j] = newDist;
                    pq.push({newDist, {i + 1, j}});
                }
            }
            if(j + 1 < n && st.find({i, j + 1}) == st.end()) {
                int newDist = min(max(d, grid[i][j + 1]), dist[i][j + 1]);
                if(newDist < dist[i][j + 1]) {
                    dist[i][j + 1] = newDist;
                    pq.push({newDist, {i, j + 1}});
                }
            }
            st.insert({i, j});
        }
        return dist[n - 1][n - 1];
    }
};
