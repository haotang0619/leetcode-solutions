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
    long long minInversionCount(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> mp;
        int n = tmp.size();
        for(int i = 0; i < n; i++) {
            if(mp.contains(tmp[i])) continue;
            mp[tmp[i]] = i;
        }
        long long ans = LLONG_MAX, now = 0;
        SegTree st(n);
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                st.update(mp[nums[i - k]], -1);
                now -= st.query(0, mp[nums[i - k]] - 1);
            }
            now += st.query(mp[nums[i]] + 1, n - 1);
            if(i >= k - 1) ans = min(ans, now);
            st.update(mp[nums[i]], 1);
        }
        return ans;
    }
};
