// Saw editorial as hints
class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(vector<int> &init) {
        n = init.size();
        tree.resize(4 * n);
        if(n > 0) build(init, 1, 0, n - 1);
    }

    void build(vector<int> &init, int node, int l, int r) {
        if (l == r) {
            tree[node] = init[l];
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> lb, rb;
        int cnt1 = 0, l = -1, r = -1;
        for(int i = 0; i <= n; i++) {
            if(i < n) cnt1 += (s[i] - '0');
            if(i < n && s[i] == '0') {
                if(l == -1) l = i;
                r = i;
            } else if(l != -1) {
                lb.push_back(l), rb.push_back(r);
                l = -1, r = -1;
            }
        }
        
        int m = lb.size();
        vector<int> v(m);
        for(int i = 0; i < m - 1; i++) {
            v[i] = (rb[i] - lb[i] + 1) + (rb[i + 1] - lb[i + 1] + 1);
        }
        SegTree st(v);
        
        int sz = queries.size();
        vector<int> ans(sz);
        for(int i = 0; i < sz; i++) {
            int ql = queries[i][0], qr = queries[i][1];
            int i1 = lower_bound(rb.begin(), rb.end(), ql) - rb.begin();
            int i2 = upper_bound(lb.begin(), lb.end(), qr) - lb.begin() - 1;
            int val1 = 0, val2 = 0, val3 = 0;
            if(i1 + 1 <= i2) {
                val1 = rb[i1] - max(lb[i1], ql) + 1;
                if(i1 + 1 == i2) val1 += min(rb[i2], qr) - lb[i2] + 1;
                else val1 += rb[i1 + 1] - lb[i1 + 1] + 1;
            }
            if(i2 - 1 >= i1) {
                val2 = min(rb[i2], qr) - lb[i2] + 1;
                if(i2 - 1 == i1) val2 += rb[i1] - max(lb[i1], ql) + 1;
                else val2 += rb[i2 - 1] - lb[i2 - 1] + 1;
            }
            if(i1 + 2 < i2) val3 = st.query(i1 + 1, i2 - 2);
            int maxVal = max(max(val1, val2), val3);
            ans[i] = maxVal + cnt1;
        }
        return ans;
    }
};
