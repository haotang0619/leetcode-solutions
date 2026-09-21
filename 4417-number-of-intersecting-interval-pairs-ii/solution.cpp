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
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<int> nums;
        for(auto& x : intervals) nums.insert(nums.end(), {x[0], x[1]});
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

        int n = intervals.size(), sz = mp.size();
        long long ans = 0;
        SegTree st1(sz), st2(sz);
        for(long long i = 0; i < n; i++) {
            int l = intervals[i][0], r = intervals[i][1];
            ans += (i - st1.query(0, mp[l] - 1) - st2.query(mp[r] + 1, sz - 1));
            st1.update(mp[r], 1), st2.update(mp[l], 1);
        }
        return ans;
    }
};
