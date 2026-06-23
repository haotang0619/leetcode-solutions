class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<vector<int>> e(n);
        for(auto &x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n, false);
        queue<int> qu;
        qu.push(source);
        vis[source] = true;
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for(auto &v : e[u]) {
                if(v == destination) return true;
                if(vis[v]) continue;
                vis[v] = true;
                qu.push(v);
            }
        }
        return false;
    }
};
