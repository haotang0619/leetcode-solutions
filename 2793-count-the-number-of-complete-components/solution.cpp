class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        for(auto &x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n, false);
        queue<int> qu;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int ecnt = 0, vcnt = 0;
            vis[i] = true;
            qu.push(i);
            while(!qu.empty()) {
                int u = qu.front();
                qu.pop();
                vcnt++;
                for(auto &v : e[u]) {
                    ecnt++;
                    if(vis[v]) continue;
                    vis[v] = true;
                    qu.push(v);
                }
            }
            if(vcnt == 1 || vcnt * (vcnt - 1) == ecnt) ans++;
        }
        return ans;
    }
};
