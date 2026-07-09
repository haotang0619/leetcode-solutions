// Saw all hints
class DSU {
public:
    vector<int> dsu;

    DSU(int n) {
        dsu.resize(n);
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = edges.size() + 1, ans = n;
        vector<vector<int>> e(n);
        for(auto& x : edges) e[x[0]].push_back(x[1]), e[x[1]].push_back(x[0]);
        
        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 0);
        sort(nodes.begin(), nodes.end(), [&](int& a, int& b) {
            return vals[a] < vals[b];
        });
        
        DSU dsu(n);
        unordered_map<int, int> mp;
        int prev = -1;
        for(auto& u : nodes) {
            if(prev != vals[u]) mp.clear();
            for(auto& v : e[u]) {
                if(vals[u] < vals[v]) continue;
                int i1 = dsu.find(u), i2 = dsu.find(v);
                if(mp[i1] == 0) mp[i1] = 1;
                if(mp[i2] == 0 && vals[v] == vals[u]) mp[i2] = 1;
                if(i1 == i2) continue;
                ans += mp[i1] * mp[i2];
                dsu.unite(i2, i1);
                mp[i2] += mp[i1];
            }
            prev = vals[u];
        }
        return ans;
    }
};
