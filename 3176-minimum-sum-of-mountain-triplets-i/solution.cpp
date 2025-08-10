// Already used this solution for Q2909.
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
    int minimumSum(vector<int>& nums) {
        SegTree st(nums);
        int ans = INT_MAX;
        for(int i = 1; i < nums.size() - 1; i++) {
            int min1 = st.query(1, 0, st.n - 1, 0, i - 1);
            int min2 = st.query(1, 0, st.n - 1, i + 1, st.n - 1);
            if(min1 < nums[i] && min2 < nums[i]) {
                ans = min(ans, min1 + nums[i] + min2);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
