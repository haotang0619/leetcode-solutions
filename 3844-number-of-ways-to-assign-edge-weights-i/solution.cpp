class Solution {
public:
    int mod = 1e9 + 7;
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b > 0) {
            if(b % 2) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return (int)res;
    }

    void dfs(vector<vector<int>>& e, int node, int prev, int lv, int &max_lv) {
        max_lv = max(lv, max_lv);
        for(auto x : e[node]) {
            if(x == prev) continue;
            dfs(e, x, node, lv + 1, max_lv);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> e(edges.size() + 2, vector<int>({}));
        for(auto x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        int max_lv = 0;
        dfs(e, 1, 1, 0, max_lv);
        return fastPow(2LL, max_lv - 1);
    }
};
