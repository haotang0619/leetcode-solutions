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
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void upd(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] += val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) upd(node * 2, l, mid, idx, val);
            else upd(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int idx, int val) {
        upd(1, 0, n - 1, idx, val);
    }

    int qry(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return qry(node * 2, l, mid, ql, qr) + qry(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int query(int l, int r) {
        return qry(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pSum(n, 0);
        for(int i = 0; i < n; i++) {
            pSum[i] = nums[i] == target ? 1 : -1;
            if(i > 0) pSum[i] += pSum[i - 1];
        }
        vector<int> init(2 * n + 1, 0);
        for(int i = 0; i < n; i++) init[pSum[i] + n]++;
        SegTree st(init);
        long long ans = 0;
        int shift = 0;
        for(int i = 0; i < n; i++) {
            ans += st.query(n + 1 + shift, 2 * n);
            st.update(pSum[i] + n, -1);
            shift = pSum[i];
        }
        return ans;
    }
};
