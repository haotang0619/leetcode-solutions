class DSU {
public:
    vector<int> dsu;
    vector<int> rank;

    DSU(int n) {
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
        rank.assign(n, 1);
    }

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    int getRank(int x) {
        return rank[find(x)];
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        dsu[b] = a;
        rank[a] += rank[b];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = m * m;
        DSU dsu(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;
                int idx = i * m + j;
                if(i > 0 && grid[i - 1][j] == 1) dsu.unite(idx - m, idx);
                if(j > 0 && grid[i][j - 1] == 1) dsu.unite(idx - 1, idx);
                ans = max(ans, dsu.getRank(idx));
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue;
                unordered_set<int> tmp;
                int idx = i * m + j;
                if(i > 0 && grid[i - 1][j] == 1) tmp.insert(dsu.find(idx - m));
                if(i < m - 1 && grid[i + 1][j] == 1) tmp.insert(dsu.find(idx + m));
                if(j > 0 && grid[i][j - 1] == 1) tmp.insert(dsu.find(idx - 1));
                if(j < m - 1 && grid[i][j + 1] == 1) tmp.insert(dsu.find(idx + 1));
                int size = 1;
                for(auto& x : tmp) size += dsu.getRank(x);
                ans = max(ans, size);
            }
        }
        return ans;
    }
};
