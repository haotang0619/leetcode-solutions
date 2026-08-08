class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> e(n);
        for(auto& inv : invocations) e[inv[0]].push_back(inv[1]);
        vector<bool> sus(n, false), vis(n, false);
        sus[k] = vis[k] = true;
        queue<int> qu;
        qu.push(k);
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for(auto& v : e[u]) {
                if(vis[v]) continue;
                sus[v] = vis[v] = true;
                qu.push(v);
            }
        }

        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            qu.push(i);
            while(!qu.empty()) {
                int u = qu.front();
                qu.pop();
                for(auto& v : e[u]) {
                    if(sus[v]) {
                        vector<int> ans(n);
                        iota(ans.begin(), ans.end(), 0);
                        return ans;
                    }
                    if(vis[v]) continue;
                    vis[v] = true;
                    qu.push(v);
                }
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!sus[i]) ans.push_back(i);
        }
        return ans;
    }
};
