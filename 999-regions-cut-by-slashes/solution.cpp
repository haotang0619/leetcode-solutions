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

    void unite4(int a, int b, int c, int d) {
        dsu[find(b)] = dsu[find(c)] = dsu[find(d)] = find(a);
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(4 * n * n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int idx = i * n + j;
                vector<int> pieces(4);
                for(int k = 0; k < 4; k++) pieces[k] = idx * 4 + k;
                if(grid[i][j] == ' ') {
                    dsu.unite4(pieces[0], pieces[1], pieces[2], pieces[3]);
                } else if(grid[i][j] == '/') {
                    dsu.unite(pieces[0], pieces[1]);
                    dsu.unite(pieces[2], pieces[3]);
                } else {
                    dsu.unite(pieces[0], pieces[3]);
                    dsu.unite(pieces[1], pieces[2]);
                }
                if(i > 0) {
                    int prevBottom = (idx - n) * 4 + 2;
                    dsu.unite(pieces[0], prevBottom);
                }
                if(j > 0) {
                    int prevRight = (idx - 1) * 4 + 3;
                    dsu.unite(pieces[1], prevRight);
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0; i < 4 * n * n; i++) st.insert(dsu.find(i));
        return st.size();
    }
};
