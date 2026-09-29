class SegTree {
public:
    int n;
    vector<int> tree;
    vector<bool> lazy;

    SegTree(vector<int> &init) {
        n = init.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int> &init, int node, int l, int r) {
        if(l == r) {
            tree[node] = init[l];
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void push(int node, int l, int r) {
        if(!lazy[node] || l == r) return;
        int mid = (l + r) / 2;
        tree[node * 2] = (mid - l + 1) - tree[node * 2];
        tree[node * 2 + 1] = (r - mid) - tree[node * 2 + 1];
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        lazy[node] = false;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            tree[node] = (r - l + 1) - tree[node];
            lazy[node] = !lazy[node];
            return;
        }
        push(node, l, r);

        int mid = (l + r) / 2;
        if(ql <= mid) update(node * 2, l, mid, ql, min(mid, qr));
        if(qr > mid) update(node * 2 + 1, mid + 1, r, max(ql, mid + 1), qr);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int ql, int qr) {
        update(1, 0, n - 1, ql, qr);
    }

    int getSum() {
        return tree[1];
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegTree st(nums1);
        long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<long long> ans;
        for(auto& q : queries) {
            int type = q[0];
            if(type == 1) {
                int l = q[1], r = q[2];
                st.update(l, r);
            } else if(type == 2) {
                long long p = q[1];
                sum += p * st.getSum();
            } else ans.push_back(sum);
        }
        return ans;
    }
};
