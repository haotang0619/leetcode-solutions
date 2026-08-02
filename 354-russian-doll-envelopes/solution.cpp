class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) tree[node] = val;
        else {
            int m = (l + r) / 2;
            if(idx <= m) update(node * 2, l, m, idx, val);
            else update(node * 2 + 1, m + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) return tree[node];
        int m = (l + r) / 2;
        return max(query(node * 2, l, m, ql, qr), query(node * 2 + 1, m + 1, r, ql, qr));
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        SegTree st(1e5 + 1);
        unordered_map<int, int> tmp;
        int ans = 1, prev = -1;
        for(auto& env : envelopes) {
            int w = env[0], h = env[1];
            if(w != prev) {
                for(auto& [idx, val] : tmp) st.update(idx, val);
                tmp.clear();
            }
            tmp[h] = max(tmp[h], st.query(0, h - 1) + 1);
            ans = max(ans, tmp[h]);
            prev = w;
        }
        return ans;
    }
};
