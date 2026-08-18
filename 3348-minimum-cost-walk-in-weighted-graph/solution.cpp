class DSU {
public:
    vector<int> dsu;
    vector<int> vals;
    
    DSU(int n) : dsu(n), vals(n) {
        iota(dsu.begin(), dsu.end(), 0);
        vals.assign(n, INT_MAX);
    }
    
    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b, int w) {
        a = find(a), b = find(b);
        vals[a] &= (vals[b] & w);
        dsu[b] = a;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for(auto& x : edges) {
            int u = x[0], v = x[1], w = x[2];
            dsu.unite(v, u, w);
        }
        vector<int> ans;
        for(auto& q : query) {
            int u = q[0], v = q[1];
            if(dsu.find(u) != dsu.find(v)) ans.push_back(-1);
            else ans.push_back(dsu.vals[dsu.find(u)]);
        }
        return ans;
    }
};
