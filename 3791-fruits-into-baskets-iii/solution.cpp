class SegTree {
public:
    vector<int> tree;

    SegTree(vector<int> &init) {
        int n = init.size();
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
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return min(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

class Solution {
public:
    int binarySearch(vector<int>& fruits, vector<int>& indices, int size) {
        int n = fruits.size(), l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(fruits[indices[m]] > size) r = m;
            else l = m + 1;
        }
        return fruits[indices[l]] > size ? l : l + 1;
    }
    
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> indices(n), revert(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return fruits[a] < fruits[b];
        });
        for(int i = 0; i < n; i++) revert[indices[i]] = i;
        SegTree st(indices);
        int ans = n;
        for(auto &bas : baskets) {
            int idx = binarySearch(fruits, indices, bas);
            int found = st.query(1, 0, n - 1, 0, idx - 1);
            if(found != INT_MAX) {
                ans--;
                st.update(1, 0, n - 1, revert[found], INT_MAX);
            }
        }
        return ans;
    }
};
