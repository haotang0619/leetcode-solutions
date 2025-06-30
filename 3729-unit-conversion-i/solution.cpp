class Solution {
public:
    int modulo = 1e9 + 7;

    void dfs(vector<vector<pair<int, int>>> &e, vector<int> &ans, long long w, int node, int prev) {
        ans[node] = (int)w;
        for(auto x : e[node]) {
            auto [next, weight] = x;
            if(next == prev) continue;
            dfs(e, ans, (w * weight) % modulo, next, node);
        }
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        vector<vector<pair<int, int>>> e(n, vector<pair<int, int>>({}));
        for(auto x : conversions) {
            int f = x[0], t = x[1], w = x[2];
            e[f].push_back({t, w});
        }
        vector<int> ans(n, 1);
        dfs(e, ans, 1LL, 0, 0);
        return ans;
    }
};
