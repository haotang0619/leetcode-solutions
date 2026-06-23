// Asked GPT
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
        a = find(a), b = find(b);
        dsu[b] = a;
    }
};

class Solution {
public:
    // [weight, index, i, j]
    int kruskal(vector<vector<int>>& e, int n, int in, int out) {
        DSU dsu(n);
        int m = e.size(), w = 0;
        if(in >= 0) {
            dsu.unite(e[in][2], e[in][3]);
            w += e[in][0];
        }
        for(int i = 0; i < m; i++) {
            if(i == in || i == out) continue;
            if(dsu.find(e[i][2]) == dsu.find(e[i][3])) continue;
            dsu.unite(e[i][2], e[i][3]);
            w += e[i][0];
        }
        int now = dsu.find(0);
        for(int i = 1; i < n; i++) {
            if(now != dsu.find(i)) return -1;
        }
        return w;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> e(m);
        for(int i = 0; i < m; i++) e[i] = {edges[i][2], i, edges[i][0], edges[i][1]};
        sort(e.begin(), e.end());
        int w = kruskal(e, n, -1, -1);
        vector<vector<int>> ans(2);
        for(int i = 0; i < m; i++) {
            int w1 = kruskal(e, n, -1, i);
            if(w != w1) ans[0].push_back(e[i][1]);
            else {
                int w2 = kruskal(e, n, i, -1);
                if(w == w2) ans[1].push_back(e[i][1]);
            }
        }
        return ans;
    }
};
