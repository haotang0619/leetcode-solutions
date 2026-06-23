class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> e(n + 1);
        for(auto &r : roads) {
            e[r[0]].push_back({r[1], r[2]});
            e[r[1]].push_back({r[0], r[2]});
        }
        vector<int> vis(n + 1, false);
        vis[1] = true;
        queue<int> qu;
        qu.push(1);
        int ans = INT_MAX;
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for(auto [v, d] : e[u]) {
                ans = min(ans, d);
                if(vis[v]) continue;
                vis[v] = true;
                qu.push(v);
            }
        }
        return ans;
    }
};
