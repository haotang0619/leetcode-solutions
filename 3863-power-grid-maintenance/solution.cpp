class DSU {
public:
    int n;
    vector<int> dsu, minOpIdx;
    vector<vector<int>> groups;
    vector<bool> ops;

    DSU(int c) {
        n = c + 1;
        dsu.resize(n); 
        minOpIdx.assign(n, 0);
        groups.resize(n);
        ops.assign(n, true);
        iota(dsu.begin(), dsu.end(), 0);
    }

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        dsu[find(b)] = find(a);
    }

    void initGroups() {
        for(int i = 1; i < n; i++) groups[find(i)].push_back(i);
    }

    void turnOff(int i) {
        int x = find(i);
        ops[i] = false;
        auto& gp = groups[x];
        auto& idx = minOpIdx[x];
        while(idx < gp.size() && !ops[gp[idx]]) idx++;
    }

    int query(int i) {
        if(ops[i]) return i;
        int x = find(i);
        auto& gp = groups[x];
        auto& idx = minOpIdx[x];
        return idx < gp.size() ? gp[idx] : -1;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        DSU dsu(c);
        for(auto& conn : connections) dsu.unite(conn[0], conn[1]);
        dsu.initGroups();
        for(auto& q : queries) {
            int type = q[0], x = q[1];
            if(type == 1) ans.push_back(dsu.query(x));
            else dsu.turnOff(x);
        }
        return ans;
    }
};
