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
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n = nums.size();
        vector<long long> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pSum[i] = pSum[i - 1] + nums[i - 1];
        }
        pSum.erase(unique(pSum.begin(), pSum.end()), pSum.end());
        sort(pSum.begin(), pSum.end());
        
        SegTree st(pSum.size());
        int idx0 = lower_bound(pSum.begin(), pSum.end(), 0) - pSum.begin();
        st.update(idx0, 1);

        long long ans = 0, now = 0;
        // ((now - prev) - goal >= k) or (goal - (now - prev) >= k) 
        // (prev <= now - goal - k) or (prev >= now - goal + k)
        for(int i = 0; i < n; i++) {
            now += nums[i];
            long long low = now - goal - k, up = now - goal + k;
            int idxLow = upper_bound(pSum.begin(), pSum.end(), low) - pSum.begin() - 1;
            int idxUp = lower_bound(pSum.begin(), pSum.end(), up) - pSum.begin();
            if(low != up) {
                long long add = st.query(0, idxLow) + st.query(idxUp, pSum.size() - 1);
                ans += add;
            } else ans += st.query(0, pSum.size() - 1);
            
            int idxNow = lower_bound(pSum.begin(), pSum.end(), now) - pSum.begin();
            st.update(idxNow, 1);
        }
        return ans;
    }
};
