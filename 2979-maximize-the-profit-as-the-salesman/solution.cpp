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
            tree[node] = max(tree[node], val);
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        SegTree st(n + 1);
        sort(offers.begin(), offers.end(), [](auto& a, auto& b) {
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        for(auto& offer : offers) {
            int l = offer[0] + 1, r = offer[1] + 1, g = offer[2];
            st.update(r, st.query(0, l - 1) + g);
        }
        return st.query(0, n);
    }
};
