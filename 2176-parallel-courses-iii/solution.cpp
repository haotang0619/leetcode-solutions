class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> e(n + 1);
        vector<int> indeg(n + 1, 0);
        for(auto& rel : relations) {
            e[rel[0]].push_back(rel[1]);
            indeg[rel[1]]++;
        }
        // Topo sort
        queue<int> qu;
        vector<int> orders;
        for(int i = 1; i <= n; i++) {
            if(indeg[i] == 0) qu.push(i);
        }
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();
            orders.push_back(u);
            for(auto& v : e[u]) {
                if(--indeg[v] == 0) qu.push(v);
            }
        }
        vector<int> start(n + 1, 0);
        int ans = 0;
        for(auto& u : orders) {
            int t = start[u] + time[u - 1];
            ans = max(ans, t);
            for(auto& v : e[u]) start[v] = max(start[v], t);
        }
        return ans;
    }
};
