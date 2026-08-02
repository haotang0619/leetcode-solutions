class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

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
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
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
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        SegTree st(n - 1);
        for(int i = 0; i < n - 1; i++) {
            if(s[i] != s[i + 1]) st.update(i, 1);
        }
        vector<int> ans;
        for(auto& q : queries) {
            int type = q[0];
            if(type == 1) {
                int j = q[1];
                if(j - 1 >= 0) {
                    if(s[j - 1] == s[j]) st.update(j - 1, 1);
                    else st.update(j - 1, 0);
                }
                if(j + 1 < n) {
                    if(s[j + 1] == s[j]) st.update(j, 1);
                    else st.update(j, 0);
                }
                s[j] = s[j] == 'A' ? 'B' : 'A';
            } else {
                int l = q[1], r = q[2];
                int cnt = st.query(l, r - 1);
                ans.push_back(r - l - cnt);
            }
        }
        return ans;
    }
};
