class Solution {
public:
    void dfs(vector<int> &v, int node, vector<vector<int>> &e, vector<bool> &seen) {
        seen[node] = true;
        for(auto x : e[node]) {
            if(seen[x]) continue;
            v.push_back(x);
            dfs(v, x, e, seen);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n, vector<int>({}));
        for(auto x : edges) {
            int f = x[0], t = x[1];
            e[t].push_back(f);
        }
        vector<vector<int>> ans(n, vector<int>({}));
        for(int i = 0; i < n; i++) {
            vector<bool> seen(n, false);
            dfs(ans[i], i, e, seen);
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
