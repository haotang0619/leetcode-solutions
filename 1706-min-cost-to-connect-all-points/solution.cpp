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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> e;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                e.push_back({dist, {i, j}});
            }
        }
        sort(e.begin(), e.end());
        int ans = 0;
        DSU dsu(n);
        for(auto &x : e) {
            auto [d, p] = x;
            auto [i, j] = p;
            if(dsu.find(i) == dsu.find(j)) continue;
            ans += d;
            dsu.unite(i, j);
        }
        return ans;
    }
};
