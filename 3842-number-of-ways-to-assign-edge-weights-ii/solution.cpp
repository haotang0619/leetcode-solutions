// Asked GPT for the Tarjan's LCA Algo
class DSU {
public:
    vector<int> dsu;

    DSU(int n) {
        dsu.resize(n + 1);
        iota(dsu.begin(), dsu.end(), 0);
    }

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        dsu[find(b)] = find(a);
    }
};

class Solution {
public:
    void dfs(DSU& dsu, vector<vector<int>>& e, unordered_map<int, vector<pair<int, int>>>& mp, vector<int>& levels, vector<int>& lens, int u, int parent, int lv) {
        levels[u] = lv;
        for(auto& v : e[u]) {
            if(v == parent) continue;
            dfs(dsu, e, mp, levels, lens, v, u, lv + 1);
            dsu.unite(u, v);
        }
        for(auto& [v, idx] : mp[u]) {
            if(levels[v] > -1) {
                int lca = dsu.find(v);
                int l1 = levels[u], l2 = levels[v], l3 = levels[lca];
                lens[idx] = l1 + l2 - 2 * l3;
            }
        }

    }

    int mod = 1e9 + 7;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Build edges
        int n = edges.size() + 1;
        vector<vector<int>> e(n + 1);
        for(auto& x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        
        // Build queries map for the Tarjan's LCA Algo
        unordered_map<int, vector<pair<int, int>>> mp; // [node, query_idx]
        int m = queries.size();
        for(int i = 0; i < m; i++) {
            auto& q = queries[i];
            mp[q[0]].push_back({q[1], i});
            mp[q[1]].push_back({q[0], i});
        }
        
        // Find the path lengths between each query
        DSU dsu(n);
        vector<int> levels(n + 1, -1);
        vector<int> lens(m);
        dfs(dsu, e, mp, levels, lens, 1, -1, 0);

        // Get the answers for each length
        vector<int> powers(n);
        powers[0] = 0, powers[1] = 1;
        for(int i = 2; i < n; i++) powers[i] = (powers[i - 1] * 2) % mod;
        vector<int> ans(m);
        for(int i = 0; i < m; i++) ans[i] = powers[lens[i]];
        return ans;
    }
};
