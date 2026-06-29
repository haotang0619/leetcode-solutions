class DSU {
public:
    vector<int> dsu;

    DSU(int n, int col) {
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
        for(int i = 0; i < col; i++) dsu[i] = 0;
        for(int i = n - col; i < n; i++) dsu[i] = n - 1;
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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        DSU dsu(n, col);
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        for(int i = n - 1; i >= 0; i--) {
            int r = cells[i][0], c = cells[i][1];
            int idx = (r - 1) * col + (c - 1);
            if(c > 1 && grid[r - 1][c - 2]) dsu.unite(idx, idx - 1);
            if(c <= col - 1 && grid[r - 1][c]) dsu.unite(idx, idx + 1);
            if(r > 1 && grid[r - 2][c - 1])  dsu.unite(idx, idx - col);
            if(r <= row - 1 && grid[r][c - 1]) dsu.unite(idx, idx + col);
            if(dsu.find(0) == dsu.find(n - 1)) return i;
            grid[r - 1][c - 1] = true;
        }
        return 0;
    }
};
