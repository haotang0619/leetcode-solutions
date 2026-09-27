class SegTree {
public:
    int n;
    vector<long long> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
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

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> mp(n);
        for(int i = 0; i < n; i++) mp[nums1[i]] = i;
        SegTree st1(n), st2(n);
        long long ans = 0;
        for(auto& num : nums2) {
            int idx = mp[num];
            ans += st2.query(0, idx - 1);
            st2.update(idx, st1.query(0, idx - 1));
            st1.update(idx, 1);
        }
        return ans;
    }
};
