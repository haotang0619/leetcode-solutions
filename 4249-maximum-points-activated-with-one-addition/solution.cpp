class DSU {
public:
    vector<int> dsu, size;

    DSU(int n) {
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
        size.assign(n, 1);
    }

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        dsu[b] = dsu[a], size[a] += size[b];
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> v(n); // [idx, x, y]
        for(int i = 0; i < n; i++) v[i] = {i, points[i][0], points[i][1]};

        DSU dsu(n);
        sort(v.begin(), v.end(), [&](auto& a, auto& b) {
            return get<1>(a) < get<1>(b);
        });
        auto prev = v[0];
        for(int i = 1; i < n; i++) {
            auto& [prevIdx, prevX, prevY] = prev;
            auto& [idx, x, y] = v[i];
            if(prevX == x) dsu.unite(prevIdx, idx);
            else prev = v[i];
        }
        sort(v.begin(), v.end(), [&](auto& a, auto& b) {
            return get<2>(a) < get<2>(b);
        });
        prev = v[0];
        for(int i = 1; i < n; i++) {
            auto& [prevIdx, prevX, prevY] = prev;
            auto& [idx, x, y] = v[i];
            if(prevY == y) dsu.unite(prevIdx, idx);
            else prev = v[i];
        }
        vector<int> mxSizes = {0, 0};
        for(int i = 0; i < n; i++) {
            if(dsu.find(i) != i) continue;
            int r = dsu.size[i];
            if(r > mxSizes[1]) mxSizes[1] = r;
            if(mxSizes[1] > mxSizes[0]) swap(mxSizes[0], mxSizes[1]);
        }
        return mxSizes[0] + mxSizes[1] + 1;
    }
};
