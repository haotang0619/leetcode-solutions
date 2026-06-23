class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<vector<int>, vector<int>>> e(n);
        for(auto &x : redEdges) e[x[0]].first.push_back(x[1]);
        for(auto &x : blueEdges) e[x[0]].second.push_back(x[1]);
        vector<pair<bool, bool>> vis(n, {false, false}); // From red or blue
        vis[0].first = vis[0].second = true;
        queue<tuple<int, int, int>> qu; // [idx, prev edge, dist]
        qu.push({0, -1, 0});
        vector<int> ans(n, -1);
        while(!qu.empty()) {
            auto [u, prev, dist] = qu.front();
            qu.pop();
            if(ans[u] == -1) ans[u] = dist;
            auto [redges, bedges] = e[u];
            if(prev != 0) {
                for(auto &v : redges) {
                    if(vis[v].first) continue;
                    vis[v].first = true;
                    qu.push({v, 0, dist + 1});
                }
            }
            if(prev != 1) {
                for(auto &v : bedges) {
                    if(vis[v].second) continue;
                    vis[v].second = true;
                    qu.push({v, 1, dist + 1});
                }
            }
        }
        return ans;
    }
};
