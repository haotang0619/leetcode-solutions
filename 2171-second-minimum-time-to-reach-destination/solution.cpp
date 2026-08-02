class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> e(n + 1);
        for(auto& x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        vector<vector<int>> dist(n + 1, vector(2, INT_MAX));
        dist[1][0] = 0;
        queue<pair<int, int>> qu; // [d, u]
        qu.push({0, 1});
        while(!qu.empty()) {
            auto [d, u] = qu.front();
            qu.pop();
            if(d > dist[u][1]) continue;
            for(auto& v : e[u]) {
                if(d + 1 >= dist[v][1]) continue;
                if(d + 1 < dist[v][0]) {
                    dist[v][0] = d + 1;
                    qu.push({dist[v][0], v});
                } else if(d + 1 > dist[v][0]) {
                    dist[v][1] = d + 1;
                    qu.push({dist[v][1], v});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < dist[n][1]; i++) {
            if((ans / change) % 2 == 1) ans = (ans + change) - (ans % change);
            ans += time;
        }
        return ans;
    }
};
