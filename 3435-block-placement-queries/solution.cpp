// Saw 2 hints
class SegTreeLazy {
public:
    vector<int> tree, lazy;

    SegTreeLazy(vector<int> &init) {
        int n = init.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(init, 1, 0, n - 1);
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

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (l != r) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeUpdate(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdate(node * 2, l, mid, ql, qr, val);
        rangeUpdate(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return INT_MIN;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = queries.size();
        int maxPos = min(50000, 3 * n);
        
        vector<int> dist(maxPos + 1);
        for(int i = 0; i <= maxPos; i++) dist[i] = maxPos - i;
        SegTreeLazy st(dist);
        set<int> obs;
        obs.insert(maxPos);
        
        vector<bool> ans;
        for(auto q : queries) {
            int type = q[0], x = q[1], sz = type == 2 ? q[2] : -1;
            if(type == 1) {
                auto it = obs.lower_bound(x);
                int prevObs = 0, nextObs = *it;
                if(it != obs.begin()) prevObs = *prev(it);
                st.rangeUpdate(1, 0, maxPos, prevObs, x - 1, x - nextObs);
                obs.insert(x);
            } else {
                auto it = obs.lower_bound(x);
                int prevObs = 0;
                if(it != obs.begin()) prevObs = *prev(it);
                int max1 = st.query(1, 0, maxPos, 0, prevObs - 1), max2 = x - prevObs;
                ans.push_back(max1 >= sz || max2 >= sz);
            }
        }
        return ans;
    }
};
