class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(vector<int> &init) {
        n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int> &init, int node, int l, int r) {
        if (l == r) {
            tree[node] = init[l];
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MIN;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

class Solution {
public:
    // Saw topic after a new test case was added:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegTree st(baskets);
        int ans = 0;
        for(auto x : fruits) {
            int l = 0, r = st.n - 1;
            if(st.query(1, 0, st.n - 1, l, r) < x) {
                ans++;
                continue;
            }
            while(l != r) {
                int mid = (l + r) / 2;
                int left = st.query(1, 0, st.n - 1, l, mid);
                if(left >= x) r = mid;
                else l = mid + 1;
            }
            st.update(1, 0, st.n - 1, l, 0);
        }
        return ans;
    }
};
