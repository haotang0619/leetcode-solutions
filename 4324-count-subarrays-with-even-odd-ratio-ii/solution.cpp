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
    // y * a - x * b >= 0
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        unordered_map<long long, int> mp;
        int n = nums.size();
        long long now = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) now += a;
            else now -= b;
            mp[now]++;
        }
        
        vector<pair<long long, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end());
        int m = v.size();
        vector<int> pSum(m + 1, 0);
        for(int i = 1; i <= m; i++) pSum[i] = pSum[i - 1] + v[i - 1].second;
        SegTree st(m);
        
        long long ans = 0, thres = 0;
        for(int i = 0; i < n; i++) {
            int idx = lower_bound(v.begin(), v.end(), make_pair(thres, 0)) - v.begin();
            int sub = 0;
            if(idx < m) sub = st.query(idx, m - 1);
            ans += pSum[m] - pSum[idx] - sub;

            if(nums[i] % 2 == 1) thres += a;
            else thres -= b;
            int idx1 = lower_bound(v.begin(), v.end(), make_pair(thres, 0)) - v.begin();
            st.update(idx1, 1);
        }
        return ans;
    }
};
