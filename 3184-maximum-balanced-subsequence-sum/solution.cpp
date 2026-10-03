class SegTree {
public:
    int n;
    vector<long long> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, LLONG_MIN);
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = max(tree[node], val);
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return LLONG_MIN;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> diffs;
        for(int i = 0; i < n; i++) diffs.push_back(nums[i] - i);
        sort(diffs.begin(), diffs.end());
        diffs.erase(unique(diffs.begin(), diffs.end()), diffs.end());
        
        unordered_map<int, int> mp;
        int m = diffs.size();
        for(int i = 0; i < m; i++) mp[diffs[i]] = i;

        SegTree st(m);
        for(int i = 0; i < n; i++) {
            int idx = mp[nums[i] - i];
            long long val = st.query(0, idx);
            if(val == LLONG_MIN) val = 0;
            val += nums[i];
            val = max(val, (long long)nums[i]);
            st.update(idx, val);
        }
        return st.query(0, m - 1);
    }
};
