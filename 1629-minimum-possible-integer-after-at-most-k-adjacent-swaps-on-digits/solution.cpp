#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;

class SegTree {
public:
    int n;
    vector<pii> tree;

    SegTree(vector<int> &init) {
        n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int> &init, int node, int l, int r) {
        if (l == r) {
            tree[node] = {init[l], l};
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = {val, idx};
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    pii query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {INT_MAX, INT_MAX};
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return min(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    pii query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        vector<int> init(n);
        ordered_set<int> os;
        for(int i = 0; i < n; i++) init[i] = num[i] - '0', os.insert(i);
        SegTree st(init);
        
        string ans;
        for(int i = 0; i < n; i++) {
            int cnt = min(k, n - 1 - i), r = *os.find_by_order(cnt);
            auto [mn, idx] = st.query(0, r);
            ans += ('0' + mn);
            k -= os.order_of_key(idx), os.erase(idx);
            st.update(idx, INT_MAX);
        }
        return ans;
    }
};
