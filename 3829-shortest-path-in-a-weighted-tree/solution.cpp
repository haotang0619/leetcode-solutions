// Reviewed Euler's Tour through this
class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] += val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> e(n + 1);
        for(auto& x : edges) {
            e[x[0]].push_back({x[1], x[2]});
            e[x[1]].push_back({x[0], x[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX), in(n + 1, -1), out(n + 1, -1);
        vector<pair<int, int>> parents(n + 1, {-1, -1});
        int time = -1;
        auto dfs = [&](auto&& self, int u, int p, int w) -> void {
            dist[u] = w;
            in[u] = ++time;
            for(auto& [v, w1] : e[u]) {
                if(v == p) continue;
                parents[v] = {u, w1};
                self(self, v, u, w + w1);
            }
            out[u] = time;
        };
        dfs(dfs, 1, -1, 0);

        // SegTree + DiffArray
        vector<int> ans;
        SegTree st(n + 1);
        for(auto& q : queries) {
            int type = q[0];
            if(type == 1) {
                int u = q[1], v = q[2], w = q[3];
                int child = parents[u].first == v ? u : v;
                int diff = w - parents[child].second;
                parents[child].second = w;
                st.update(in[child], diff), st.update(out[child] + 1, -diff);
            } else {
                int x = q[1];
                ans.push_back(dist[x] + st.query(0, in[x]));
            }
        }
        return ans;
    }
};
